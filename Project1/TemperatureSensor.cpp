#include "TemperatureSensor.h"
#include <time.h> 

TemperatureSensor::TemperatureSensor(string ID, short state, int Temp, int internalTempe) : Sensor(ID, state, internalTempe)
{
	temperature = Temp;
}

TemperatureSensor::~TemperatureSensor()
{
}

int TemperatureSensor::getValueOfSensor()
{
	return temperature;
}

void TemperatureSensor::setValueOfSensor(int newTemperature)
{
	temperature = newTemperature;
}

void TemperatureSensor::randomizeSensorValue()
{
	unsigned int rnd = (unsigned int)time(NULL);
	srand(rnd);
	setValueOfSensor(rand() % 5 + 30);
}