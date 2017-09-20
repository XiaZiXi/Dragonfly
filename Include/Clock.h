#pragma once

// The clock, for timing (such as game loop).
class Clock {
private:
	long m_prevTime; // Previous time delta() called (in microsec).
	
	// Returns the current time, -1 if error.
	// Units in microseconds.
	long getCurrentTime();

public:
	// Sets prevTime to current time.
	Clock();

	// Return elapsed time since delta() was last called, -1 if error.
	// Resets clock time.
	// Units in microseconds.
	long delta();

	// Return elapsed time since delta() was last called, -1 if error.
	// Does not reset clock time.
	// Units in microseconds.
	long split();
};