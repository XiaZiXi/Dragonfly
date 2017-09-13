#include <stdarg.h>

#include "LogManager.h"

df::LogManager::LogManager()
{
	setType("LogManager");

	m_doFlush = false;
	m_p_file = NULL;
}

df::LogManager::LogManager(LogManager const &) {}

void df::LogManager::operator=(LogManager const &) {}

df::LogManager::~LogManager()
{
}

df::LogManager &df::LogManager::getInstance()
{
	static LogManager logManager;
	return logManager;
}

int df::LogManager::startUp()
{
	Manager::startUp();

	m_p_file = std::fopen(LOGFILE_NAME.c_str(), "w");
	if (m_p_file == NULL)
	{
		return -1;
	}
	else
	{
		writeLog("LogManager::startUp(): Starting up the Log Manager!");
		return 0;
	}
}

void df::LogManager::shutDown()
{
	LM.writeLog("LogManager::shutDown(): Shutting down the Log Manager.");
	if (m_p_file != NULL)
	{
		fclose(m_p_file);
	}

	Manager::shutDown();
}

void df::LogManager::setFlush(bool doFlush)
{
	m_doFlush = doFlush;
}

int df::LogManager::writeLog(const char * fmt, ...) const
{
	int result;

	va_list args;
	va_start(args, fmt);
	result = vfprintf(m_p_file, fmt, args);
	fprintf(m_p_file, "\n");
	va_end(args);

	if (m_doFlush)
	{
		fflush(m_p_file);
	}

	return result;
}

