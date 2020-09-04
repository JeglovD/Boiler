#pragma once

#include <Arduino.h>
#include <OneWire.h>

class Temperature {
public:
	Temperature(const Temperature&) = delete;
	Temperature& operator=(Temperature&) = delete;
	static Temperature& Instance() { static Temperature temperature; return temperature; }
	void Loop();
	const double* operator()();

private:
	Temperature();

	OneWire mOneWire{ 2 };
	double mTemperature;
	unsigned long mMillisPrevious{ 0 };
};
