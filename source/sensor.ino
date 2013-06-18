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


#include "sensor.h"

/*!
	 Constructor. Assigns the pin information passed as parameter.
	 \param[in] pin_p Pin to be read
	 \param[in] analog_p true if it is an analog pin
*/
Sensor::Sensor(int pin_p, bool analog_p): lastValue(0.0), lastTime(0.0), valid(false),
																					pin(pin_p), analog(analog_p)
{

}
