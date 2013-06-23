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

#include "voltage.h"

VoltageSensor *v;

const int BATTERY_PIN = 0;
const int CURRENT_PIN = 1;

const double VDIVIDER_R1 = 516.0e3; //!< R1 value of the battery voltage divider
const double VDIVIDER_R2 = 326.0e3; //!< R2 value of the battery voltage divider

void setup()
{
	v = new VoltageSensor(BATTERY_PIN, CURRENT_PIN, VDIVIDER_R1, VDIVIDER_R2, 0.1);

  Serial.begin(9600); 
  Serial.println("Hello world!"); 
}

void loop()
{
	v->trigger();

	delay(2000);
}
