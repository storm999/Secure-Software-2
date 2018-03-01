#include "Device.h"

Device::Device()
{
	//pre defined sensors
	Sensor* humuditySensor = new HumiditySensor("Humidity Sensor1 ", ACTIVE, 85, 25);
	Sensor* temperatureSensor = new TemperatureSensor("Temperature Sensor1 ", ACTIVE, 2, 25);
	Sensor* pressureSensor = new PressureSensor("Pressure Sensor1 ", ACTIVE, 25, 25);

	sensors.push_back(humuditySensor);
	sensors.push_back(temperatureSensor);
	sensors.push_back(pressureSensor);
}

Device::~Device()
{
}

void Device::displayValues()
{
	for (unsigned i = 0; i < sensors.size(); i++)
	{
		cout << sensors[i]->getSensorID() << "  Value: " << sensors[i]->getValueOfSensor() << endl;
	}
}

void Device::randomizeSensorValueAll()
{
	for (unsigned i = 0; i < sensors.size(); i++)
	{
		if (sensors[i]->getStateOfSensor() == 0)
		{
			sensors[i]->randomizeSensorValue();
		}
	}
}

vector<Sensor*> Device::getSensors()
{
	return sensors;
}


void Device::log()
{
	stringstream stream;
		for (unsigned i = 0; i < sensors.size(); i++)
	{
		stream << sensors[i]->getSensorID() << ":" << endl;
		stream << "Internal temperature: " << sensors[i]->getInternalTemperaure() << " celcius degree" << endl;;
		stream << "The value read from sensor:" << sensors[i]->getValueOfSensor() <<endl;
	}
	string logMessage = stream.str();
	
	
	ofstream writeLogs("Log.txt", ios::app);
	if (!writeLogs)
	{
		cerr << "Error, cant access to log file." << endl;
		exit(1);
	}
	writeLogs << logMessage;
	writeLogs.close();
}


void Device::printLogToScreen()
{
	ifstream fin("Log.txt");
	string temp;

	while (getline(fin, temp))
	{
		cout << temp << endl;
	}
	fin.close();
	fin.clear();
}