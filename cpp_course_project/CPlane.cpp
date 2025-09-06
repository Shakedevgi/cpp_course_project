#include "Plane.h"
#include <iostream>
#include <string> 
#include "Plane.h"

int CPlane::nextSerial = 100;

CPlane::CPlane(int chairsNumber, const std::string& model)
{
	setIfValid(nextSerial++, chairsNumber, model);
}

bool CPlane::isValid(int serial, const std::string& m, int chairs)
{
	return serial > 0 && chairs > 0 && !m.empty();
}

void CPlane::setIfValid(int serial, int chairs, const std::string& m)
{
	if (isValid(serial, m, chairs )) {
		serialNumber = serial;
		chairsNumber = chairs;
		model = m;
	}
	else {
		std::cerr << "";
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

CPlane& CPlane::operator=(const CPlane& other) {
	if (this != &other) {
		serialNumber = other.serialNumber;
		model = other.model;
		chairsNumber = other.chairsNumber;
	}
	return *this; 
}

bool CPlane::operator==(const CPlane& other) const
{
	return serialNumber == other.serialNumber;
}

//prefix
CPlane& CPlane::operator++()
{
	++chairsNumber;
	return *this;
}

//postfix
CPlane CPlane::operator++(int)
{
	CPlane tmp(*this);
	++(*this);
	return tmp;
}

std::ostream& operator<<(std::ostream& os, const CPlane& p)
{
	os << "plane " << p.serialNumber
		<< " degem " << p.model
		<< "  seats: " << p.chairsNumber << "\n";
	return os;
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