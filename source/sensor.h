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

	private:
		double lastValue;
		unsigned int lastTime;
		bool valid;

		int pin;
		bool analog;
};


#endif
