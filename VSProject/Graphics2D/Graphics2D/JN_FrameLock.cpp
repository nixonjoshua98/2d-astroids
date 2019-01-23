
#include "JN_FrameLock.h"

#include <SDL.h>


JN_FrameLock::JN_FrameLock(int fps, int& _rFps): rFps(_rFps)
{
	start = std::chrono::system_clock::now();

	deltaTime = 1000 / fps; // ms
}

JN_FrameLock::~JN_FrameLock()
{
	int dur = GetTimeSpan();

	// Casting to remove warnings
	WaitForMs(std::fmax(deltaTime - dur, 0));

	rFps = 1000 / GetTimeSpan();
}

int JN_FrameLock::GetTimeSpan()
{
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> span = end - start;
	return (int)span.count(); // ms (1000ms = 1s)
}

void JN_FrameLock::WaitForMs(int ms)
{
	SDL_Delay(ms);
	//Sleep(ms)	// Windows.h
}