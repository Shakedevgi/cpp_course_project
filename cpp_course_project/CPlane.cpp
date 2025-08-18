#include "Plane.h"
#include <iostream>
#include <string> 
#include "Plane.h"

CPlane::CPlane(int serialNumber, int chairsNumber, const std::string& model)
{
	setIfValid(serialNumber, chairsNumber, model);
}

bool CPlane::isValid(int serial, int chairs, const std::string& m)
{
	return serial > 0 && chairs > 0 && !m.empty();
}

void CPlane::setIfValid(int serial, int chairs, const std::string& m)
{
	if (isValid(serial, chairs, m)) {
		serialNumber = serial;
		chairsNumber = chairs;
		model = m;
	}
	else {
		std::cerr << "Invalid CPlane data.\n";
	}
}

CPlane::CPlane(const CPlane& other)
{
	this->serialNumber = other.serialNumber;
	this->model = other.model;
	this->chairsNumber = other.chairsNumber;
}

CPlane::~CPlane()
{
}



void CPlane::Print() const
{
	std::cout << "Plane " << serialNumber << " degem " << model << " seats " << chairsNumber << std::endl;
}

int CPlane::GetSerialNumber() const
{
	return serialNumber;
}

const std::string& CPlane::GetModel() const
{
	return model;
}

int CPlane::GetChairsNumber() const
{
	return chairsNumber;
}

bool CPlane::IsEqual(const CPlane& other) const
{
	return (serialNumber == other.serialNumber);
}