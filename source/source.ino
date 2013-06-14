#include "voltage.h"

VoltageSensor *v;

const int BATTERY_PIN = 0;
const int CURRENT_PIN = 1;

void setup()
{
	v = new VoltageSensor(BATTERY_PIN, CURRENT_PIN, 470.0e3, 330.0e3, 0.1);

  Serial.begin(9600); 
  Serial.println("Hello world!"); 
}

void loop()
{
	v->trigger();

	delay(2000);
}
