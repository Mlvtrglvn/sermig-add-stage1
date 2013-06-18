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

#include "voltage.h"
#include "sensor.h"

/*!
	Empty constructor, can receive just the pins info
	\param[in] vpin_p Battery voltage input analog pin
	\param[in] ipin_p Voltage point for current computation pin
*/
VoltageSensor::VoltageSensor(int vpin_p, int ipin_p) : Sensor(vpin_p, true), vpin(0), 
									ipin(1), R1(0.0),
									R2(0.0), Rminus(0.0),
									batteryVoltage(0.0),
									batteryCurrent(0.0), partitionRatio(0.0)
{
	//Void reads
	analogRead(vpin);
	analogRead(vpin);
	analogRead(ipin);
	analogRead(ipin);

}

/*!
	Standard constructor with parameter assignment
	\param[in] vpin_p Battery voltage input analog pin
	\param[in] ipin_p Voltage point for current computation pin
	\param[in] R1p Value of R1
	\param[in] R2p Value of R2
	\param[in] Rminusp Value of the small resistance used for current computation
*/
VoltageSensor::VoltageSensor(int vpin_p, int ipin_p, double R1p, double R2p, double Rminusp):
	Sensor(vpin_p, true), vpin(vpin_p), ipin(ipin_p), R1(R1p), R2(R2p), Rminus(Rminusp),
	batteryVoltage(0.0), batteryCurrent(0.0), partitionRatio(0.0)
{
	//Void reads
	analogRead(vpin);
	analogRead(vpin);
	analogRead(ipin);
	analogRead(ipin);

	updateCoefficients(); // Update the partition ratio	
}

/*!
	Empty destructor
*/
VoltageSensor::~VoltageSensor() {}

/*
	Trigger the measurement of both battery voltage and current and output them to the serial.
	\warning{May take time}
*/
bool VoltageSensor::trigger()
{
	int v_val;
	int i_val;
	
	v_val = analogRead(vpin);
	v_val = analogRead(vpin);

	i_val = analogRead(ipin);
	i_val = analogRead(ipin);

	// Computations of the actual values, given the various resistance and ratio parameter
	// and the dynamic of the analog pins
	batteryVoltage = double(v_val) * 5.0 / (1023 * partitionRatio);
	batteryCurrent = double(i_val) * 5.0 /(1023 *  Rminus);
	valid = true;

	// Output to the serial (sort of CSV lines)
	Serial.print("VOLT,");
	Serial.print(batteryVoltage);
	Serial.print(",");
	Serial.print(batteryCurrent);
	Serial.print("\n");

	return true;
}

/*!
	Modify the partition ratio of the voltage partitioner applied to every read
*/
void VoltageSensor::updateCoefficients()
{
	partitionRatio = R2 / (R1 + R2); 
}
