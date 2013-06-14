#ifndef SENSOR_H
#define SENSOR_H

/*!
	Generic class representic a sensor
*/
class Sensor {
	public:
		Sensor();
		virtual ~Sensor() {}

	private:
		double lastValue;
		unsigned int lastTime;
		bool valid;
};


#endif
