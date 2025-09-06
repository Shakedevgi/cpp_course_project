// ===== CCrewMember.cpp =====
#include "CrewMember.h"
#include <iostream>
#include <string>

int CCrewMember::nextEmployeeNumber = CCrewMember::START_ID;

// ctor with address (unambiguous: 3 params; default at the END)
CCrewMember::CCrewMember(const std::string& name, const CAddress& address, int airTime)
    : name(), airTime(0), address(address), employeeNumber(nextEmployeeNumber++)
{
    if (!Setname(name)) {
        std::cerr << "Invalid crew member name\n";
        throw std::invalid_argument("Invalid name");
    }
    if (airTime < 0) {
        std::cerr << "Invalid crew member airtime\n";
        throw std::invalid_argument("Invalid airtime");
    }
    this->airTime = airTime;

    // address was initialized in the initializer list; validate once
    if (!CAddress::isValid(this->address.GetCity(), this->address.GetStreet(), this->address.GetHouseNumber())) {
        std::cerr << "Invalid crew member address\n";
        throw std::invalid_argument("Invalid address");
    }
}

// ctor WITHOUT address – provide a valid internal default address to avoid throwing
CCrewMember::CCrewMember(const std::string& name, int airTime)
    : name(), airTime(0), address(/*house*/0, /*street*/"Unknown",  /*city*/"Tel Aviv"), employeeNumber(nextEmployeeNumber++)
{
    if (!Setname(name)) {
        std::cerr << "Invalid crew member name\n";
        throw std::invalid_argument("Invalid name");
    }
    if (airTime < 0) {
        std::cerr << "Invalid crew member airtime\n";
        throw std::invalid_argument("Invalid airtime");
    }
    this->airTime = airTime;
}

bool CCrewMember::isValid(const std::string& name, int airTime, const CAddress& address)
{
    return !name.empty()
        && airTime >= 0
        && CAddress::isValid(address.GetCity(), address.GetStreet(), address.GetHouseNumber());
}

std::ostream& operator<<(std::ostream& os, const CCrewMember& crewMember) {
    os << "Crew Member " << crewMember.name << " minutes " << crewMember.airTime;
    return os;
}

const std::string& CCrewMember::GetName() const { return name; }
int CCrewMember::GetAirTime() const { return airTime; }
const CAddress& CCrewMember::GetAddress() const { return address; }

bool CCrewMember::SetAddress(const CAddress& newAddress)
{
    if (CAddress::isValid(newAddress.GetCity(), newAddress.GetStreet(), newAddress.GetHouseNumber())) {
        address = newAddress;
        return true;
    }
    std::cerr << "Invalid address provided.\n";
    return false;
}

bool CCrewMember::Setname(const std::string& newName)
{
    if (!newName.empty()) {
        name = newName;
        return true;
    }
    std::cerr << "Invalid name provided.\n";
    return false;
}

void CCrewMember::UpdateAddress(const CAddress& newAddress)
{
    if (CAddress::isValid(newAddress.GetCity(), newAddress.GetStreet(), newAddress.GetHouseNumber())) {
        address = newAddress;
    }
    else {
        std::cerr << "Invalid address provided for update.\n";
    }
}

bool CCrewMember::operator==(const CCrewMember& other) const {
    return this->employeeNumber == other.employeeNumber;
}

int CCrewMember::getEmployeeNumber() const {
    return employeeNumber;
}

CCrewMember::CCrewMember(const CCrewMember& other)
    : name(other.name),
    airTime(other.airTime),
    address(other.address),
    employeeNumber(other.employeeNumber) // if the spec wants a NEW ID on copy, change to nextEmployeeNumber++
{}

CCrewMember::~CCrewMember() {}

CCrewMember& CCrewMember::operator=(const CCrewMember& other)
{
    if (this != &other) {
        this->name = other.name;
        this->airTime = other.airTime;
        this->address = other.address;
        // employeeNumber is const – cannot be reassigned
    }
    return *this;
}

bool CCrewMember::operator!() const
{
    return !isValid(name, airTime, address);
}

// return reference to allow chaining: crew += 10 += 20;
CCrewMember& CCrewMember::operator+=(int minutes) {
    if (minutes < 0) {
        std::cerr << "Invalid minutes provided. Must be non-negative.\n";
        return *this;
    }
    airTime += minutes;
    return *this;
}
