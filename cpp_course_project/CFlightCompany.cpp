#include "FlightCompany.h"

bool CFlightCompany::isValid(const std::string& name)
{
	return !name.empty();
}


CFlightCompany::CFlightCompany(const std::string& name)
{
	if (isValid(name))
		this->nameOfCompany = name;
}

CFlightCompany::CFlightCompany(const CFlightCompany& other)
{
	this->nameOfCompany = other.nameOfCompany;
}

CFlightCompany::~CFlightCompany() {};


std::string CFlightCompany::GetName() const { return nameOfCompany; }

bool CFlightCompany::SetName(const std::string& name) {
	if (name.empty()) return false;
	nameOfCompany = name;
	return true;
}

void CFlightCompany::Print() const {
	std::cout << "Flight Company: " << nameOfCompany << std::endl;
}