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

#include "timer_pump.h"
#include "sensor.h"

/*!
	Empty constructor, can receive just the pins info
	\param[in] vpin_p Battery voltage input analog pin
	\param[in] ipin_p Voltage point for current computation pin
*/
TimerPump::TimerPump(int pin_p) : Sensor(pin_p, false), timer_value(LOW)
{
	pinMode(0, OUTPUT);
	pinMode(7, OUTPUT);


	//digitalWrite(pin, LOW);
	digitalWrite(0, LOW);
	digitalWrite(7, LOW);
}

/*!
	Empty destructor
*/
TimerPump::~TimerPump() {}

/*
	Trigger the measurement of both battery voltage and current and output them to the serial.
	\warning{May take time}
*/
bool TimerPump::trigger()
{

	digitalWrite(0, timer_value);
	digitalWrite(7, timer_value);

	if(timer_value == HIGH) {
		Serial.println("PUMP ON");
		timer_value = LOW;
		}

	else {
		Serial.println("PUMP OFF");
		timer_value = HIGH;
	}


	return true;
}

