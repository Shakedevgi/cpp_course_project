#include <iostream>
#include <string> 

#include "Address.h"

CAddress::CAddress(int houseNumber, const std::string& street,  const std::string& city)
{
	setIfValid(city, street, houseNumber);
}

CAddress::CAddress(int houseNumber, const char* street, const char* city)
{
	std::string streetStr = (street == nullptr) ? "" : std::string(street);
	std::string cityStr = (city == nullptr) ? "" : std::string(city);
	setIfValid(cityStr, streetStr, houseNumber);
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


std::ostream& operator<<(std::ostream& os, const CAddress& address)
{
	os << address.street << " " << address.houseNumber << " " << address.city << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, CAddress& address)
{
	std::string street, city;
	int houseNumber;
	
	std::cout << "Enter street: ";
	is >> street;
	std::cout << "Enter house number: ";
	is >> houseNumber;
	std::cout << "Enter city: ";
	is >> city;
	
	if (CAddress::isValid(city, street, houseNumber)) {
		address.street = street;
		address.houseNumber = houseNumber;
		address.city = city;
	} else {
		std::cerr << "Invalid address input. Address not updated.\n";
	}
	return is;
}

bool CAddress::operator==(const CAddress& other) const{
	return this->street == other.street && this->houseNumber == other.houseNumber && this->city == other.city;
}

bool CAddress::operator!=(const CAddress& other) const{
	return !(*this == other);
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

std::string CAddress::GetCurrentAddress() const
{
	return street + " " + std::to_string(houseNumber) + "," + city;
}

CAddress& CAddress::operator=(const CAddress& other)
{
	if (this != &other) {
		this->city = other.city;
		this->street = other.street;
		this->houseNumber = other.houseNumber;
	}
	return *this;
}
