#ifndef VOLTAGE_H
#define VOLTAGE_H

#include "sensor.h"

class VoltageSensor: public Sensor {
	public:
		VoltageSensor(int vpin_p = 0, int ipin_p = 1);
		VoltageSensor(int vpin_p, int ipin_p, double R1p, double R2p, double Rminusp = 0.0);
		virtual ~VoltageSensor();

		bool trigger();

	private:
		int vpin; //!< Pin to receive battery voltage from voltage divider
		int ipin; //!< Pin to receive voltage used to compute current (resitance toward battery minus)
		double R1, R2, Rminus;
		double batteryVoltage;
		double batteryCurrent;
		double partitionRatio;

		void updateCoefficients();

};

#endif
