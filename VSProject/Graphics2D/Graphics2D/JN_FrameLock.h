#ifndef JN_FRAME_LOCK_H
#define JN_FRAME_LOCK_H

#include <chrono>

class JN_FrameLock
{
public:
	JN_FrameLock(int fps, int& _rFps);	// Constructor
	~JN_FrameLock();					// Deconstructor, stops the clock and locks the fps

private:
	std::chrono::system_clock::time_point start;	// The time at construction

	int deltaTime;	// Time (ms) which each cycle (frame) should take
	int& rFps;		// Passed in by reference

	int GetTimeSpan();			// Return the time sicne construction
	void WaitForMs(int ms);		// Pause execution for <ms> time
};

#endif