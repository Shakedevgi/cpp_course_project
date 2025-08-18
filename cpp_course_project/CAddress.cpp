#include <iostream>
#include <string> 

#include "Address.h"

CAddress::CAddress(int houseNumber, const std::string& street,  const std::string& city)
{
	setIfValid(city, street, houseNumber);
}

bool CAddress::isValid(const std::string& c, const std::string& s, int h)
{
	return !c.empty() && !s.empty() && h >= 0;
}

void CAddress::setIfValid(const std::string& c, const std::string& s, int h)
{
	if (isValid(c, s, h)) {
		this->city = c;
		this->street = s;
		this->houseNumber = h;
	}
	else {
		std::cerr << "Invalid address: city/street must be non-empty and houseNumber >= 0.\n";
	}
}


CAddress::CAddress(const CAddress& other)
{
	this->city = other.city;
	this->street = other.street;
	this->houseNumber = other.houseNumber;
}

CAddress::~CAddress()
{
}


void CAddress::Print () const
{
	std::cout << street << " " << houseNumber << "," << city << std::endl;
}

const std::string& CAddress::GetCity() const
{
	return city;
}

const std::string& CAddress::GetStreet() const
{
	return street;
}

int CAddress::GetHouseNumber() const
{
	return houseNumber;
}

void CAddress::UpdateAddress(const std::string& newCity, const std::string& newStreet, int newHouseNumber)
{
	city = newCity;
	street = newStreet;
	houseNumber = newHouseNumber;
}
