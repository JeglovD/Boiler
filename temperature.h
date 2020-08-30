#pragma once

#include <Arduino.h>

class Temperature {
public:
	Temperature(const Temperature&) = delete;
	Temperature& operator=(Temperature&) = delete;
	static Temperature& Instance() { static Temperature temperature; return temperature; }
	void Loop();
	const double* operator()();

private:
	Temperature();

	double mTemperature;
};
