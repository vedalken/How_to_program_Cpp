#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <thread>
#include <functional>

template <typename Iterator, typename T>
struct AccumulatorBlock
{
    void operator()(Iterator begin, Iterator end, T& result)
    {
        result = std::accumulate(begin, end, result);
    }
};

template <typename Iterator, typename T>
T ParallelAccumulate(Iterator a_begin, Iterator a_end, T a_init)
{
    if (a_begin == a_end) {
        return a_init;
    }

    // minimum number of used threads
    const size_t minThreads = 2;

    // minimum number of elements per thread
    const size_t minPerThread = 50;

    // number of elements to sum
    const size_t length = std::distance(a_begin, a_end);

    // maximal number of threads (without main thread)
    const size_t maxThreads = (length + minPerThread - 1) / minPerThread;

    // number of hardware treads available (0 means not defined)
    const size_t hardwareThreads = std::thread::hardware_concurrency();

    // determine smallest number of used threads
    const size_t numThreads = std::min((hardwareThreads == 0 ? 
        minThreads : hardwareThreads), maxThreads);

    // block size per thread
    const size_t blockSize = length / numThreads;

    // spawing number of threads (without taking into account the main thread)
    std::vector<std::thread> threads(numThreads - 1);
    std::vector<T> result(numThreads);

    Iterator blockStart = a_begin;
    for (size_t i = 0; i < (numThreads-1); ++i)
    {
        Iterator blockEnd = blockStart;
        std::advance(blockEnd, blockSize);
        threads[i] = std::thread(AccumulatorBlock<Iterator,T>(),
            blockStart, blockEnd, std::ref(result[i]));
        blockStart = blockEnd;
    }

    std::cout << "Spawn " << numThreads << " threads\n";

    // main thread 
    AccumulatorBlock<Iterator,T>()(blockStart, a_end,
        std::ref(result[numThreads-1]));

    // wait threads to complete
    std::for_each(threads.begin(), threads.end(),
        std::mem_fn(&std::thread::join));

    // accumulate all partial sum
    return std::accumulate(result.cbegin(), result.cend(), a_init);
}

int main()
{
    std::vector<long long> vec(10000);
    std::iota (vec.begin(), vec.end(), 0);

    long long result = ParallelAccumulate(vec.cbegin(), vec.cend(), 0L);

    std::cout << "Sum from 0 to " << vec.size()-1 << ": " << result << std::endl;
    return 0;
}
