#include "voltage.h"
#include "sensor.h"

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

	updateCoefficients();	
}

VoltageSensor::~VoltageSensor() {}

bool VoltageSensor::trigger()
{
	int v_val;
	int i_val;
	
	v_val = analogRead(vpin);
	v_val = analogRead(vpin);

	i_val = analogRead(ipin);
	i_val = analogRead(ipin);

	batteryVoltage = double(v_val) / partitionRatio;
	batteryCurrent = double(i_val) / Rminus;
	valid = true;

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
