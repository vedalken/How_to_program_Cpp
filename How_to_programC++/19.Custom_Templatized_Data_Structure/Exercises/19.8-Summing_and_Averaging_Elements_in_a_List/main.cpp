/*
 * Program generates random numbers and inserts the number in ascending
 * order (by default). Internally is used enhanced list data structure.
 *
 */

#include "list.h"
#include <functional>
#include <random>
#include <ctime>

int main()
{
    std::default_random_engine engine(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution randomInt(0, 100);

    List<int> list1;
    for (int i = 0; i < 25; ++i) {
	list1.insert(randomInt(engine));
    }

    std::cout << list1 << std::endl;

    return 0;
}
