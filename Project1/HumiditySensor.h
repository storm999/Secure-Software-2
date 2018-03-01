#pragma once
#include "Sensor.h"
class HumiditySensor :	public Sensor
{
private:
	unsigned short humidity;
public:

	HumiditySensor(string ID, short state, int setHumidity, int internalTempe);
	~HumiditySensor();

	int getValueOfSensor();
	void setValueOfSensor(unsigned short);
	
	void randomizeSensorValue();

};

