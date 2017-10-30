#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

template <typename T>
bool palindrom(const std::vector<T>& v)
{
    for (size_t i=0, j=v.size()-1; i != j; ++i, --j)
    {
	// check palindrom property
        if (v.at(i) != v.at(j)) {
	    return false;
	}
    }

    return true;
}

int main()
{
    std::vector<int> palin{1,2,3,4,3,2,1};
    std::vector<int> npalin{1,2,3,4,5};

    std::cout << "Vector: ";
    std::copy(palin.cbegin(), palin.cend(),
	      std::ostream_iterator<int>(std::cout, " "));
    std::cout << " " << (palindrom(palin) ? "is" : "is not")
	      << " palindrom" << std::endl;

    std::cout << "\nVector: ";
    std::copy(npalin.cbegin(), npalin.cend(),
	      std::ostream_iterator<int>(std::cout, " "));
    std::cout << " " << (palindrom(npalin) ? "is" : "is not")
	      << " palindrom" << std::endl;

    return 0;
}
