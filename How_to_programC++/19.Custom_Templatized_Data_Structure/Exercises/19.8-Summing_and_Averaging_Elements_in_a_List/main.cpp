/*
 * Program generates random numbers and inserts the number in ascending
 * order (by default). Internally is used enhanced list data structure.
 *
 * Program takes 3 optional arguments:
 *
 *   ./main [length] [min_num] [max_num]
 *
 * Arguments:
 *
 *   length -- length of generated numbers (default: 25)
 *   min_num -- minimum generated value (default: 0)
 *   max_num -- maximal generated value (default: 100)
 *
 */

#include "list.h"
#include <functional>
#include <random>
#include <ctime>
#include <algorithm>

int main(int argc, char* argv[])
{
    size_t length = 25;
    long int min_gen_num = 0;
    long int max_gen_num = 100;

    switch (argc) {
	case 4:
	    max_gen_num = std::strtol(argv[3], NULL, 0);
	    [[fallthrough]]; // allow fall to next case
	case 3: 
	    min_gen_num = std::strtol(argv[2], NULL, 0);
	    [[fallthrough]]; // allow fall to next case
	case 2:
	    length = std::strtoul(argv[1], NULL, 0);
	    break;
	case 1:
	    // nothing to do
	    break;
	default:
	    std::cout << "Usage:\n";
	    std::cout << "\t" << argv[0] << " [length] [min_num] [max_num]\n\n";
	    return 1;
    }

    std::default_random_engine engine(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution randomInt(min_gen_num, max_gen_num);

    List<int> list1;
    for (size_t i = 0; i < length; ++i) {
	list1.insert(randomInt(engine));
    }

    long int sum = std::accumulate(list1.cbegin(),
                                   list1.cend(),
                                   0L);
    double avg = static_cast<double>(sum) / length;

    std::cout << "list: " << list1 << std::endl;
    std::cout << "length: " << length << std::endl;
    std::cout << "sum: " << sum << std::endl;
    std::cout << "average: " << avg << std::endl;
    std::cout << "generated range: [ " << min_gen_num << ", " 
                                       << max_gen_num << " ]" << std::endl;

    return 0;
}
