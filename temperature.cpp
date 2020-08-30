#include "temperature.h"
#include "heater.h"

Temperature::Temperature() {
}

void Temperature::Loop() {
	mTemperature -= (mTemperature - 25.0) / 200.0;
	mTemperature += Heater::Instance()() * 0.6;
}

const double* Temperature::operator()() {
	return &mTemperature;
}