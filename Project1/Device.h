#ifndef Device_h
#define Device_h
#pragma once

#include <iostream>
#include <vector>
#include "Sensor.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "PressureSensor.h"
#include <sstream>
#include <fstream>

using namespace std;

class Device
{
private:
	vector<Sensor*> sensors;
public:
	Device();
	~Device();

	void displayValues();
	void randomizeSensorValueAll();
	void log();
	void printLogToScreen();
	vector<Sensor*> getSensors();
	
};

#endif 