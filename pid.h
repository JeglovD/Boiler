#pragma once

#include "temperature.h"
#include "heater.h"

class Pid {
public:
	Pid( Temperature& sensor, Heater& actuator, const double& require, const double& proportional_coefficient, const double& integrel_coefficient, const double& differential_coefficient );
	void Loop();
	const double& Require() { return mRequire; };
	const double& Proportional() { return mProportional; };
	const double& Integral() { return mIntegral; };
	const double& Differencial() { return mDifferential; };

private:
	Temperature& mSensor;
	Heater& mActuator;
	double mRequire;
	double mProportionalCoefficient;
	double mIntegralCoefficient;
	double mDifferentialCoefficient;

	double mProportional{ 0 };
	double mIntegral{ 0 };
	double mDifferential{ 0 };

	double mErrorPrevious{ 0 };
};