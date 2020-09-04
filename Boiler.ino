#include "temperature.h"
#include "heater.h"
#include "pid.h"
#include "timer.h"

Pid pid{ Temperature::Instance(), Heater::Instance(), 28, 0.45/*0.1*/, 0/*0.0001*/, 0/*1*/ };

void setup() {
	Serial.begin(57600);

	Timer::Instance();
}

void loop() {
	if (Serial.available() > 0) {
		switch (Serial.read()) {
		case 'S':
			Serial.println("$N$;Boiler");
			Serial.println("$C$;temperature;temperature_require;heater;pid_proportional;pid_integral;pid_differential");
		}
	}

	Temperature::Instance().Loop();
	pid.Loop();

	const double* p_temperature{ Temperature::Instance()() };
	String temperature_string{ p_temperature ? String{ *p_temperature } : "-" };
	Serial.println(
		"$" + 
		temperature_string + ";" + // temperature
		String( pid.Require() ) + ";" + // temperature_require
		String( Heater::Instance()() ) + ";" + // heater
		String( pid.Proportional() ) + ";" + // pid_proportional
		String( pid.Integral() ) + ";" + // pid_integral
		String( pid.Differencial() )); // pid_differential

	delay(100);
}
