#pragma once

#include <Arduino.h>

class Heater {
public:
	static Heater& Instance() { static Heater heater; return heater; }
	const double& operator()();
	const double& operator()(const double& heater);

private:
	Heater() = default;

	double mHeater{ 1 };

	Heater(const Heater&) = delete;
	Heater& operator=(Heater&) = delete;
};