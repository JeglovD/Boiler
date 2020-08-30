#include "heater.h"

const double& Heater::operator()() {
	return mHeater;
}

const double& Heater::operator()(const double& heater) {
	mHeater = min( max(heater, 0), 1);
	return mHeater;
}