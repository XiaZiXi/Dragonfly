#include <Windows.h>

#include "LogManager.h"
#include "Clock.h"
#include "GameManager.h"

df::GameManager::GameManager()
{
	setType("GameManager");

	m_gameOver = false;
	m_frameTime = FRAME_TIME_DEFAULT;
}

df::GameManager::GameManager(GameManager const &) {}

void df::GameManager::operator=(GameManager const &) {}

df::GameManager &df::GameManager::getInstance()
{
	static GameManager gameManager;
	return gameManager;
}

int df::GameManager::startUp()
{
	Manager::startUp();
	LM.startUp();
	LM.writeLog("GameManager::startUp(): Starting up the Game Manager!");

	timeBeginPeriod(1);
	return 0;
}

void df::GameManager::shutDown()
{

	timeEndPeriod(1);
	setGameOver();

	LM.writeLog("GameManager::shutDown(): Shutting down the Game Manager.");
	LM.shutDown();
	Manager::shutDown();
}

void df::GameManager::run()
{
	Clock clock;
	while (!m_gameOver)
	{
		clock.delta();
		// Get Input.
		// Update World State.
		// Draw to Back Buffer.
		// Swap Buffers.
		long loopTime = clock.split() / 1000; // Convert from microseconds to milliseconds.
		Sleep(m_frameTime - loopTime);
	}
}

void df::GameManager::setGameOver(bool gameOver)
{
	m_gameOver = gameOver;
}

bool df::GameManager::getGameOver() const
{
	return m_gameOver;
}

int df::GameManager::getFrameTime() const
{
	return m_frameTime;
}
