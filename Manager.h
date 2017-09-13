#pragma once
#include <string>

namespace df {
class Manager {
private:
	std::string m_type;	// Manager type identifier.
	bool m_isStarted;	// True when started successfully.

protected:
	// Set type identifier of Manager.
	void setType(std::string type);

public:
	Manager();
	virtual ~Manager();

	// Get type identifier of Manager.
	std::string getType() const;

	// Startup Manager.
	// Return 0 if ok, else, negative number.
	virtual int startUp();

	// Shutdown Manager.
	virtual void shutDown();

	// Return true when startUp() was executed ok, else false.
	bool isStarted() const;
};
}