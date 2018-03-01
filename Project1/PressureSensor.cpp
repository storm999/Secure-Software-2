#include "PressureSensor.h"
#include <time.h> 
#include <iostream>
PressureSensor::PressureSensor(string ID, short state, int Temp, int internalTempe) : Sensor(ID, state, internalTempe)
{
	pressure = Temp;
}

PressureSensor::~PressureSensor()
{
}

int PressureSensor::getValueOfSensor()
{
	return (int) pressure;
}

void PressureSensor::setValueOfSensor(int pressureReadFromSensor)
{
	unsigned int rnd = (unsigned int)time(NULL);
	srand(rnd);

	unsigned short heightFactor = rand() % 20;
		
	//integer overflow checking
	
	if (((pressureReadFromSensor > 0) && (heightFactor > (UINT8_MAX + pressureReadFromSensor))) || ((pressureReadFromSensor < 0) && (heightFactor < (pressureReadFromSensor))))
	{
		cout << "OverFlow" << endl;
			return;
	}
	else 
	{
		pressure = pressureReadFromSensor - heightFactor;
	}
}

void PressureSensor::randomizeSensorValue()
{
	unsigned int rnd = (unsigned int)time(NULL);
	srand(rnd);
	setValueOfSensor(rand() % 15 + 90);
}
