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
#include "actuator.h"

/*!
	Constructor, simply call base class constructor
	\param[in] pin_p Pin of the control line of the relais
	\param[in] initial_value First value to be given to the relais (LOW opens, HIGH closes)
*/
TimerPump::TimerPump(int pin_p, int initial_value) : Actuator(pin_p, initial_value)
{
}

/*!
	Empty destructor
*/
TimerPump::~TimerPump() {}

/*
	Trigger a check of the status of the relais, eventually changing its value
*/
bool TimerPump::trigger()
{


	// Test code, just toggles the relains command at each method call
	if(lastValueGiven == HIGH) {
		Serial.println("PUMP OFF");
		lastValueGiven = LOW;
		}

	else {
		Serial.println("PUMP ON");
		lastValueGiven = HIGH;
	}


	digitalWrite(pin, lastValueGiven);

	return true;
}

