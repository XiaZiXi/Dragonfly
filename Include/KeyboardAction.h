#pragma once

namespace df {

// Types of keyboard actions Dragonfly recognizes.
enum KeyboardAction {
	UNDEFINED_KEYBOARD_ACTION = -1, // Undefined
	KEY_PRESSED,					// Was down
	KEY_RELEASED,					// Was released
	KEY_DOWN						// Is down
};
}