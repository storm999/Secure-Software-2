#pragma once
#include "Sensor.h"
class TemperatureSensor :	public Sensor
{
private:
	int temperature;
public:

	TemperatureSensor(string ID, short state, int Temp, int internalTempe);
	~TemperatureSensor();

	void randomizeSensorValue();
	
	int getValueOfSensor();
	void setValueOfSensor(int);
};

