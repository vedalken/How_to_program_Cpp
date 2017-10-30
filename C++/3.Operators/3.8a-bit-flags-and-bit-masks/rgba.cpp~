#include <iostream>
#include <cstdint>

int main()
{
	const uint32_t redBits   = 0xFF000000;
	const uint32_t greenBits = 0x00FF0000;
	const uint32_t blueBits  = 0x0000FF00;
	const uint32_t alphaBits = 0x000000FF;

	std::cout << "Enter 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
	uint32_t pixel;
	std::cin >> std::hex >> pixel;

	uint8_t red   = (pixel & redBits) >> 24;
	uint8_t green = (pixel & greenBits) >> 16;
	uint8_t blue  = (pixel & blueBits) >> 8;
	uint8_t alpha = pixel & alphaBits;

	std::cout << "You colors contains:\n";
	std::cout << "red " << static_cast<int>(red)   << " of 255 red"
		<< "\ngreen:  " << static_cast<int>(green) << " of 255 green"
		<< "\nblue:   " << static_cast<int>(blue)  << " of 255 blue"
		<< "\nalpha:  " << static_cast<int>(alpha) << " of 255 alpha" << std::endl;

	return 0;
}
