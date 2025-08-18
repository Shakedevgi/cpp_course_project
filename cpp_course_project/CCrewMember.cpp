#include "CrewMember.h"
#include <iostream>
#include <string>

CCrewMember::CCrewMember(const std::string& name, const CAddress& address, int airTime)
	: address(address)
{
	if (!isValid(name, airTime, address)) {
		std::cerr << "Invalid crew member data\n";
		throw std::invalid_argument("Invalid data");
	}
	this->name = name;
	this->airTime = airTime;
}


bool CCrewMember::isValid(const std::string& name, int airTime, const CAddress& address)
{
	return !name.empty() && airTime >= 0 && CAddress::isValid(address.GetCity(), address.GetStreet(), address.GetHouseNumber());
}


void CCrewMember::Print() const
{
	std::cout << "cremember " << name << " minutes " << airTime << std::endl;
}

const std::string& CCrewMember::GetName() const
{
	return name;
}

int CCrewMember::GetAirTime() const
{
	return airTime;
}

bool CCrewMember::UpdateMinutes(int minutes)
{
	if (minutes < 0) {
		return false;
	}
	else
	{
		airTime += minutes;
		return true;
	}
	
}

const CAddress& CCrewMember::GetAddress() const
{
	return address;
}

bool CCrewMember::SetAddress(const CAddress& newAddress)
{
	if (CAddress::isValid(newAddress.GetCity(), newAddress.GetStreet(), newAddress.GetHouseNumber())) {
		address = newAddress;
		return true;
	}
	else {
		std::cerr << "Invalid address provided.\n";
		return false;
	}
}

bool CCrewMember::Setname(const std::string& newName)
{
	if (!newName.empty()) {
		name = newName;
		return true;
	}
	else {
		std::cerr << "Invalid name provided.\n";
		return false;
	}
}

void CCrewMember::UpdateAddress(const CAddress& newAddress)
{
	if (newAddress.isValid(newAddress.GetCity(), newAddress.GetStreet(), newAddress.GetHouseNumber())) {
		address = newAddress;
	}
	else {
		std::cerr << "Invalid address provided for update.\n";
	}
}

bool CCrewMember::IsEqual(const CCrewMember& other) const
{
	return this->name == other.name;
}

CCrewMember::CCrewMember(const CCrewMember& other) : address(other.address)
{
	this->name = other.name;
	this->airTime = other.airTime;
}

CCrewMember::~CCrewMember()
{
}



