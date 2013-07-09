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


#include "actuator.h"

/*!
	 Constructor. Assigns the pin information passed as parameter, initializes the pin as output
	 and writes the initial value selected.
	 \param[in] pin_p Pin of the actuator to be controlled
	 \param[in] initial_value First value to be written to the pin
*/
Actuator::Actuator(int pin_p, int initial_value): lastValueGiven(initial_value), lastTime(0), pin(pin_p)
{
	pinMode(pin, OUTPUT); // Set the pin as output
	digitalWrite(pin, lastValueGiven); // Write the initial value passed in the constructor to the pin
}


