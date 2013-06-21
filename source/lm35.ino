#include "lm35.h"

/*!
	Constructor. Initialize class instance with superclass constructor call.

	\param[in] pin_p Pin of the data line of the sensor
*/
TemperatureLm35::TemperatureLm35(int pin_p) : Sensor(pin_p, true) {}

/*!
	Trigger the sensor, reading and converting its data.

	Uses the conversion method of http://playground.arduino.cc/Main/LM35HigherResolution

	\return true if the data is valid
*/
bool TemperatureLm35::trigger() 
{
	unsigned int valueRead;

	analogReference(INTERNAL); // Raise the resolution of the lm35 sensor switching to 1.1V as reference of the analog pin
	valueRead = analogRead(pin); // No impedence at the pin, no need to wait.
	analogReference(DEFAULT); // Reset the reference change
	
	// Conversion expression taken from http://playground.arduino.cc/Main/LM35HigherResolution (1C = 9.31 analog reading)
	lastValue = (double) valueRead / 9.31;
	valid = true;

	// Data output to serial
	Serial.print("TEMP,");
	Serial.print(lastValue);
	Serial.print("\n");

	return true;
	
}
