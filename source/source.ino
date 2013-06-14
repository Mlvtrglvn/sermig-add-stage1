#include "voltage.h"

VoltageSensor *v;

void setup()
{
	v = new VoltageSensor(0);

  Serial.begin(9600); 
  Serial.println("Hello world!"); 
}

void loop()
{
	v->trigger();

	delay(2000);
}
