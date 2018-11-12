#include "list.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <chrono>

int main(int argc, char* argv[])
{
    size_t N = 10;
    switch (argc)
    {
	case 2:
	    N = std::strtoul(argv[1], NULL, 0);
	    break;
	case 1:
	    break;
	default:
	    std::cout << "Usage:\n";
	    std::cout << "\t" << argv[0] << " [numbers]" << std::endl;
	    return 1;
    }

    std::random_device r;
    std::default_random_engine engine(r());
    std::uniform_int_distribution<char> uniform_dist(97, 122);

    List<char> list;
    for (size_t i = 0; i < N; ++i) {
        list.insertBack(uniform_dist(engine));
    }
   
    std::cout << "original: " << list << std::endl;

    // reverse list    
    list.reverse();

    std::cout << "reverse:  " << list << std::endl;

    return 0;
}
