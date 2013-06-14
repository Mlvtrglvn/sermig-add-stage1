#include "voltage.h"
#include "sensor.h"

VoltageSensor::VoltageSensor(int pin_p) : Sensor(pin_p, true), R1(0.0),
									R2(0.0), Rminus(0.0),
									batteryVoltage(0.0),
									currentVoltage(0.0)
{
	//Void reads
	analogRead(pin);
	analogRead(pin);

}

VoltageSensor::VoltageSensor(int pin_p, double R1p, double R2p, double Rminusp):
	Sensor(pin_p, true), R1(R1p), R2(R2p), Rminus(Rminusp),
	batteryVoltage(0.0), currentVoltage(0.0)
{

}

VoltageSensor::~VoltageSensor() {}

bool VoltageSensor::trigger()
{
	int val = analogRead(pin);

	Serial.print("VOLT,");
	Serial.print(val);
	Serial.print("\n");

	return true;
}
