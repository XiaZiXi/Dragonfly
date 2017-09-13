#pragma once

#include "Manager.h"

// Default frame time (game loop time) in milliseconds (33ms == 30fps).
const int FRAME_TIME_DEFAULT = 33;

namespace df {
#define GM df::GameManager::getInstance()

class GameManager : public Manager {
private:
	GameManager();							// Private since a singleton.
	GameManager(GameManager const &);		// Don't allow copy.
	void operator=(GameManager const &);	// Don't allow assignment.

	bool m_gameOver;	// If true, then game loop should stop.
	int m_frameTime;	// Target time per game loop, in milliseconds.
	int m_loopCount;	// Number of time the game loop has been run.

public:
	// Get the singleton instance of the GameManager.
	static GameManager &getInstance();

	// Start up all GameManager services.
	int startUp();

	// Shut down all GameManager services.
	void shutDown();

	// Run game loop.
	void run();

	// Set game over status. If true (default), will stop game loop.
	void setGameOver(bool gameOver = true);

	// Get game over status.
	bool getGameOver() const;

	// Return frame time.
	// Frame time is target time for game loop, in milliseconds.
	int getFrameTime() const;
};
}