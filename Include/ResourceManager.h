#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "Manager.h"
#include "Sprite.h"

namespace df {
#define RM df::ResourceManager::getInstance()

// Maximum number of unique assets in game.
const int MAX_SPRITES = 1000;

// Delimiters used to parse Sprite files.
// The ResourceManager 'knows' file format.
const std::string FRAMES_TOKEN = "frames";
const std::string HEIGHT_TOKEN = "height";
const std::string WIDTH_TOKEN = "width";
const std::string COLOR_TOKEN = "color";
const std::string END_FRAME_TOKEN = "end";
const std::string END_SPRITE_TOKEN = "eof";

class ResourceManager : public Manager {
private:
	ResourceManager();					// Private since a singleton.
	Sprite *m_p_sprite[MAX_SPRITES];	// Array of sprites.
	int m_spriteCount;					// Count of number of loaded sprites.

	// Read single line, return line.
	std::string readLine(std::ifstream *p_file, const char *tag);

	// Read single line 'tag number', return number (ex. "frames 5").
	int readLineInt(std::ifstream *p_file, int *p_lineNum, const char *tag);

	// Read single line 'tag string', return string (ex. "color green").
	std::string readLineStr(std::ifstream *p_file, int *p_lineNum, const char *tag);

	// Read frame until 'eof', return Frame.
	Frame readFrame(std::ifstream *p_file, int *p_lineNum, int width, int height);

public:
	ResourceManager(ResourceManager const &copy) = delete;	// Don't allow copy.
	void operator=(ResourceManager const &assign) = delete;	// Don't allow assignment.

	// Get the singleton instance of the ResourceManager.
	static ResourceManager &getInstance();

	// Start up all ResourceManager services.
	int startUp();

	// Shut down ResourceManager, freeing up any allocated Sprites.
	void shutDown();

	// Load Sprite from file.
	// Assign indicated label to sprite.
	// Return 0 if ok, else -1.
	int loadSprite(std::string filename, std::string label);

	// Unload Sprite with indicated label.
	// Return 0 if ok, else -1.
	int unloadSprite(std::string label);

	// Find Sprite with indicated label.
	// Return pointer to it if found, else NULL.
	Sprite *getSprite(std::string label) const;
};
}