#include "lm35.h"

/*!
	Constructor. Initialize class instance with superclass constructor call.

	\param[in] pin_p Pin of the data line of the sensor
*/
TemperatureLm35::TemperatureLm35(int pin_p) : Sensor(pin_p, true) {}

/*!
	Trigger the sensor, reading and converting its data.

	\return true if the data is valid
*/
bool TemperatureLm35::trigger() 
{
	unsigned int valueRead;

	valueRead = analogRead(pin); // No impedence at the pin, no need to wait.
	
	lastValue = (double) valueRead; // TODO: write the conversion expression
	valid = true;

	Serial.print("TEMP,");
	Serial.print(lastValue);
	Serial.print("\n");

	return true;
	
}
