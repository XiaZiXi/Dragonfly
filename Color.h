#pragma once
#include <SFML/Graphics.hpp>

namespace df {
// Colors Dragonfly recognizes.
enum Color {
	UNDEFINED_COLOR = -1,
	BLACK = 0,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
};

// If color is not specified, use this.
const Color COLOR_DEFAULT = WHITE;

class ColorHelper {
public:
	static sf::Color convertToSFML(Color color)
	{
		switch (color)
		{
		case UNDEFINED_COLOR:
			return convertToSFML(COLOR_DEFAULT);
		case BLACK:
			return sf::Color::Black;
		case RED:
			return sf::Color::Red;
		case GREEN:
			return sf::Color::Green;
		case YELLOW:
			return sf::Color::Yellow;
		case BLUE:
			return sf::Color::Blue;
		case MAGENTA:
			return sf::Color::Magenta;
		case CYAN:
			return sf::Color::Cyan;
		case WHITE:
			return sf::Color::White;
		default:
			return convertToSFML(COLOR_DEFAULT);
		}
	}
};
}