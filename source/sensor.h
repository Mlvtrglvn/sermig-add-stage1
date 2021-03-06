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

#ifndef SENSOR_H
#define SENSOR_H

/*!
	Generic class representic a sensor
*/
class Sensor {
	public:
		Sensor(int pin_p = 0, bool analog_p = false);
		virtual ~Sensor() {}

		virtual bool trigger() = 0;

	protected:
		double lastValue; //<! Last value collected by the sensor
		unsigned int lastTime; //<! Absolute time the sensor collected the last item \warning{NOT used at the moment}
		bool valid; //!< true if the values are valid (false when the class is instantiated)

		int pin; //!< Arduino pin at which data must be read
		bool analog; //!< true if the pin is an analog pin of the Arduino board
};


#endif
