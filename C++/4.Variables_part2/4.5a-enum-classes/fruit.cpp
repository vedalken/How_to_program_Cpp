#include <iostream>
#include <cstdint>

int main()
{
	enum class Color {
		RED,
		BLUE
	};

	enum class Fruit {
		BANNANA,
		APPLE
	};

	Color color = Color::RED;
	Fruit fruit = Fruit::BANNANA;

	if (color == Color::RED)
		std::cout << "color is RED\n";
	else if (color == Color::BLUE)
		std::cout << "color is BLUE\n";
	
	enum class Vehicle : uint8_t { RED, BLUE };
	enum class People : uint8_t { YELLOW, BLUE };
	
	return 0;
}
