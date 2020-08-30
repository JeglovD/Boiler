#include "pid.h"
#include "temperature.h"

Pid::Pid(Temperature& sensor, Heater& actuator, const double& require, const double& proportional_coefficient, const double& integral_coefficient, const double& differential_coefficient):
	mSensor{ sensor },
	mActuator{ actuator },
	mRequire{ require },
	mProportionalCoefficient{ proportional_coefficient },
	mIntegralCoefficient{ integral_coefficient },
	mDifferentialCoefficient{ differential_coefficient } 
{}

void Pid::Loop() {
	const double* p_value{ mSensor() };
	if (p_value) {
		double error{ mRequire - *p_value };
		mProportional = error * mProportionalCoefficient;
		mIntegral += error * mIntegralCoefficient;
		if (mErrorPrevious)
			mDifferential = (error - mErrorPrevious) * mDifferentialCoefficient;
		mErrorPrevious = error;
		mActuator(mProportional + mIntegral + mDifferential);
	}
}