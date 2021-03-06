#include <Windows.h>

#include "WorldManager.h"
#include "LogManager.h"
#include "DisplayManager.h"
#include "InputManager.h"

#include "EventStep.h"
#include "Clock.h"
#include "GameManager.h"

df::GameManager::GameManager()
{
	setType("GameManager");

	m_gameOver = false;
	m_frameTime = FRAME_TIME_DEFAULT;
	m_loopCount = 0;
}

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
	WM.startUp();
	DM.startUp();
	IM.startUp();

	Box defaultBounds(Vector(), DM.getHorizontal(), DM.getVertical());
	WM.setBoundary(defaultBounds);
	WM.setView(defaultBounds);

	timeBeginPeriod(1);
	return 0;
}

void df::GameManager::shutDown()
{
	timeEndPeriod(1);
	setGameOver();

	IM.shutDown();
	DM.shutDown();
	WM.shutDown();
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
		//LM.writeLog("\nGameManager::run(): Running Game Loop number %d.", m_loopCount);
		IM.getInput();

		// Send step event to all objects.
		EventStep step(m_loopCount);
		onEvent(&step);

#ifdef DEBUG_TEST_OBJECT
		// Remove Objects after a few loops.
		ObjectList allObjects = WM.getAllObjects();
		ObjectListIterator iter(&allObjects);
		if (m_loopCount > 0 && m_loopCount % 10 == 0)
		{
			if (allObjects.getCount() > 0)
			{
				iter.first();
				WM.markForDelete(iter.currentObject());
			}
			else
			{
				setGameOver();
			}
		}
#endif

		WM.update();
		WM.draw();
		DM.swapBuffers();
		long loopTime = clock.split() / 1000; // Convert from microseconds to milliseconds.
		if (loopTime < m_frameTime)
		{
			Sleep(m_frameTime - loopTime);
		}
		m_loopCount++;
	}
	LM.writeLog("\nGameManager::run(): Game Over after %d loops.", m_loopCount - 1);
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
