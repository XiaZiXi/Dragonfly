#pragma once
#include "SFML/Graphics.hpp"

namespace df {
namespace Mouse {

// Set of mouse buttons recognized by Dragonfly.
enum Button {
	UNDEFINED_MOUSE_BUTTON = -1,
	LEFT = sf::Mouse::Left,
	RIGHT = sf::Mouse::Right,
	MIDDLE = sf::Mouse::Middle
};

static std::vector<Button> buttons = {
	LEFT,
	RIGHT,
	MIDDLE
};
}
}