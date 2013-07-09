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

#include "actuator.h"

/*!
 * TimerPump is the class representing the timer control via the relais.
 * It implements the logic used to control the relais.
 *
 * \warning The class must be completed with proper logic and a control strategy for the timer
 * */
class TimerPump: public Actuator {
	public:
		TimerPump(int pin_p = 0, int initial_value = LOW);
		virtual ~TimerPump();

		bool trigger();

		// All other attributes are inherithed from Actuator
};

#endif
