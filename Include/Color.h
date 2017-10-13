#pragma once
#include <SFML/Graphics.hpp>
#include "LogManager.h"

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

	static df::Color stringToColor(std::string string)
	{
		if (string == "black")
		{
			return BLACK;
		}
		else if (string == "red")
		{
			return RED;
		}
		else if (string == "green")
		{
			return GREEN;
		}
		else if (string == "yellow")
		{
			return YELLOW;
		}
		else if (string == "blue")
		{
			return BLUE;
		}
		else if (string == "magenta")
		{
			return MAGENTA;
		}
		else if (string == "cyan")
		{
			return CYAN;
		}
		else if (string == "white")
		{
			return WHITE;
		}
		else
		{
			LM.writeLog("ColorHelper::stringToColor(): Could not match string: %s. Using default color.", string.c_str());
			return COLOR_DEFAULT;
		}
	}
};
}