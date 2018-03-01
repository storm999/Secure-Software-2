#include "HumiditySensor.h"
#include <time.h> 

HumiditySensor::HumiditySensor(string ID, short state, int setHumidity, int internalTempe) : Sensor(ID, state, internalTempe)
{
	humidity = setHumidity;
}

HumiditySensor::~HumiditySensor()
{
}

int HumiditySensor::getValueOfSensor()
{
	return (int) humidity;
}

void HumiditySensor::setValueOfSensor(unsigned short setHumidity)
{
	humidity = setHumidity;
}

void HumiditySensor::randomizeSensorValue()
{
	unsigned int rnd = (unsigned int)time(NULL);
	srand(rnd);
	setValueOfSensor(rand() % 20 + 60);
}
