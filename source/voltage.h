#ifndef VOLTAGE_H
#define VOLTAGE_H

#include "sensor.h"

class VoltageSensor: public Sensor {
	public:
		VoltageSensor(int pin_p = 0);
		VoltageSensor(int pin_p, double R1p, double R2p, double Rminusp = 0.0);
		virtual ~VoltageSensor();

		bool trigger();

	private:
		double R1, R2, Rminus;
		double batteryVoltage;
		double currentVoltage;

};

#endif
