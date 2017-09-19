#pragma once

#include <stdio.h>

#include "Manager.h"

const std::string LOGFILE_NAME = "dragonfly.log";

namespace df {
#define LM df::LogManager::getInstance()

class LogManager : public Manager {
private:
	LogManager();	// Private since a singleton.

	bool m_doFlush;	// True if flush to disk after each write.
	FILE *m_p_file;	// Pointer to logfile struct.

public:
	LogManager(LogManager const &copy) = delete;		// Don't allow copy.
	void operator=(LogManager const &assign) = delete;	// Don't allow assignment.

	// If logfile is open, close it.
	~LogManager();

	// Get the one and only instance of the LogManager.
	static LogManager &getInstance();

	// Start up the LogManager (open logfile "dragonfly.log").
	int startUp();

	// Shut down the LogManager (close logfile).
	void shutDown();

	// Set flush of logfile after each write.
	void setFlush(bool doFlush = true);

	// Write to logfile. Supports printf() formatting of strings.
	// Return number of bytes written, -1 if error.
	int writeLog(const char *fmt, ...) const;
};
}