/*
	Copyright (C) 2013 Sermig

	This file is part of sermig-add-stage1.

	sermig-add-stage1 is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/


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
