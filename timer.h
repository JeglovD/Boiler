#pragma once

#include <Arduino.h>

class Timer {
public:
	static Timer& Instance() { static Timer timer; return timer; }
	void Interrupt();

private:
	Timer();

	byte mCounter;

	Timer(const Timer&) = delete;
	Timer& operator=(Timer&) = delete;
};
