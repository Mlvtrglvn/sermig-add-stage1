#ifndef LM35_h
#define LM35_h

class TemperatureLm35: public Sensor {
	public:
		TemperatureLm35(int pin_p = 2);	
		virtual ~TemperatureLm35() {}

		bool trigger();

};

#endif
