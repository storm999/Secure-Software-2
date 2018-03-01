#include "Sensor.h"

Sensor::Sensor(string ID, short state, int internalTempe)
{
	id = ID;
	internalTemperature = internalTempe;
	sensorState = state;
}

string Sensor::getSensorID()
{
	return id;
}

short Sensor::getStateOfSensor()
{
	return sensorState;
}

void Sensor::setStateOfSensor(short state)
{
	sensorState = state;
}

int Sensor::getInternalTemperaure()
{
	return internalTemperature;
}

void Sensor::setIntTempOfSensor(int Temp)
{
	internalTemperature = Temp;
}

