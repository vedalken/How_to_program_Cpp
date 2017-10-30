#include <iostream>

int main ()
{
	enum Color
	{
		COLOR_WHITE,	// assigned 0
		COLOR_BLACK,	// assigned 1
		COLOR_GREEN,	// ...
		COLOR_RED,
		COLOR_BLUE,
		COLOR_YELLOW,
		COLOR_MAGENTA,
		COLOR_CYAN	// assigned 7
	};
	
	enum Animal
	{
		ANIMAL_DOG = -3,	// assigned -3
		ANIMAL_CAT = -2,
		ANIMAL_PIG, 		// assigned -1
		ANIMAL_CHICKEN,		// assigned 0
		ANIMAL_TURKEY = 5,
		ANIMAL_HORSE = 5,
		ANIMAL_GIRAFFE		// assigned 6
	};

	Color eColor = COLOR_YELLOW;	// integer value is assigned!
	std::cout << eColor << std::endl;
	std::cout << COLOR_WHITE << std::endl;

	// Animal eAnimal = 5; 	compile error, cannot assign int to enumerator!
	// Better way to do is with static_cast, but be careful.
	Animal eAnimal = static_cast<Animal>(5);
	std::cout << eAnimal << std::endl;

	return 0;	// success!
}
