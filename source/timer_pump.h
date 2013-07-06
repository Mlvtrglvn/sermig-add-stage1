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


#ifndef TIMERPUMP_H
#define TIMERPUMP_H

#include "sensor.h"

/*!
 * Class of the battery voltage sensor based on the voltage divider.
 *
 * */
class TimerPump: public Sensor {
	public:
		TimerPump(int pin_p = 0);
		virtual ~TimerPump();

		bool trigger();


	private:
		int timer_value;
};

#endif
