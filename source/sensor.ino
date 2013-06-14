#include "sensor.h"

Sensor::Sensor(int pin_p, bool analog_p): lastValue(0.0), lastTime(0.0), valid(false),
																					pin(pin_p), analog(analog_p)
{

}
