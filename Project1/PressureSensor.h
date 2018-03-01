#pragma once
#include "Sensor.h"
class PressureSensor :	public Sensor
{
private:
	unsigned short pressure;
public:
	PressureSensor(string ID, short state, int Temp, int internalTempe);
	~PressureSensor();

	void randomizeSensorValue();
	
	int getValueOfSensor();
	void setValueOfSensor(int setPressure);
	
};

