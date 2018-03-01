#pragma once
#include <string>

using namespace std;

enum statesOfSensors { ACTIVE, INACTIVE };

class Sensor
{
private:
	string id;
	int internalTemperature;
	short sensorState;
public:

	Sensor(string, short, int);
	~Sensor() {}
	
	string getSensorID();

	int getInternalTemperaure();
	void setIntTempOfSensor(int);

	short getStateOfSensor();
	void setStateOfSensor(short);

	virtual void randomizeSensorValue() {}
	virtual int getValueOfSensor() { return NULL; }
	virtual void setValueOfSensor(int value) {}
	
};

