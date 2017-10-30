#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cout << "Usage: " << argv[0] << " <Filename> " << std::endl;
        std::exit(EXIT_FAILURE);
	}
    
    for (int count = 1; count < argc; ++count) {
        std::cout << count << " " << argv[ count ] << std::endl;
    }

	return 0;
}
