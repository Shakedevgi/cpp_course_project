#include "FlightCompany.h"
#include <iostream>

bool CFlightCompany::isValid(const std::string& name)
{
	return !name.empty();
}


CFlightCompany::CFlightCompany(const std::string& name) : numCrewMembers(0), numAircraft(0), numFlights(0)
{
	if (isValid(name))
		SetName(name);
		
	// Initialize all pointers to nullptr
	for (std::size_t i = 0; i < MAX_CREWS; i++) {
		crewMembers[i] = nullptr;
	}
	for (std::size_t i = 0; i < MAX_PLANES; i++) {
		aircraft[i] = nullptr;
	}
	for (std::size_t i = 0; i < MAX_FLIGHT; i++) {
		flights[i] = nullptr;
	}
}

// Copy constructor is deleted as per requirements

CFlightCompany::~CFlightCompany() 
{
	// Delete all allocated objects
	for (std::size_t i = 0; i < numCrewMembers; i++) {
		delete crewMembers[i];
	}
	for (std::size_t i = 0; i < numAircraft; i++) {
		delete aircraft[i];
	}
	for (std::size_t i = 0; i < numFlights; i++) {
		delete flights[i];
	}
}


std::string CFlightCompany::GetName() const { return nameOfCompany; }

bool CFlightCompany::SetName(const std::string& name) {
	if (name.empty()) return false;
	nameOfCompany = name;
	return true;
}


std::ostream& operator<<(std::ostream& os, const CFlightCompany& company)
{
	os << "Flight Company: " << company.nameOfCompany << std::endl;
	os << "Crew Members (" << company.numCrewMembers << "/" << CFlightCompany::MAX_CREWS << "):" << std::endl;
	for (std::size_t i = 0; i < company.numCrewMembers; i++) {
		if (company.crewMembers[i]) {
			os << "  " << *company.crewMembers[i] << std::endl;
		}
	}
	os << "Aircraft (" << company.numAircraft << "/" << CFlightCompany::MAX_PLANES << "):" << std::endl;
	for (std::size_t i = 0; i < company.numAircraft; i++) {
		if (company.aircraft[i]) {
			os << "  " << *company.aircraft[i] << std::endl;
		}
	}
	os << "Flights (" << company.numFlights << "/" << CFlightCompany::MAX_FLIGHT << "):" << std::endl;
	for (std::size_t i = 0; i < company.numFlights; i++) {
		if (company.flights[i]) {
			os << "  " << *company.flights[i] << std::endl;
		}
	}
	return os;
}

bool CFlightCompany::AddCrewMember(const CCrewMember& crewMember)
{
	if (numCrewMembers >= MAX_CREWS) {
		std::cerr << "Cannot add crew member: maximum capacity reached." << std::endl;
		return false;
	}

	// Check if crew member already exists (by employee number)
	for (std::size_t i = 0; i < numCrewMembers; i++) {
		if (crewMembers[i] && *crewMembers[i] == crewMember) {
			return false;
		}
	}

	// Add the crew member
	crewMembers[numCrewMembers] = new CCrewMember(crewMember);
	numCrewMembers++;
	return true;
}

bool CFlightCompany::AddPlane(const CPlane& plane)
{
	if (numAircraft >= MAX_PLANES) {
		std::cerr << "Cannot add aircraft: maximum capacity reached." << std::endl;
		return false;
	}

	// Check if aircraft already exists (by serial number)
	for (std::size_t i = 0; i < numAircraft; i++) {
		if (aircraft[i] && *aircraft[i] == plane) {
			std::cerr << "Aircraft with serial number " << plane.GetSerialNumber() << " already exists." << std::endl;
			return false;
		}
	}

	// Add the aircraft
	aircraft[numAircraft] = new CPlane(plane);
	numAircraft++;
	return true;
}

bool CFlightCompany::AddFlight(const CFlight& flight)
{
	if (numFlights >= MAX_FLIGHT) {
		std::cerr << "Cannot add flight: maximum capacity reached." << std::endl;
		return false;
	}

	// Check if flight already exists (by flight number)
	for (std::size_t i = 0; i < numFlights; i++) {
		if (flights[i] && *flights[i] == flight) {
			std::cerr << "Flight with number " << flight.GetFlightNumber() << " already exists." << std::endl;
			return false;
		}
	}

	// Add the flight
	flights[numFlights] = new CFlight(flight);
	numFlights++;
	return true;
}

bool CFlightCompany::AddCrewToFlight(int flightNumber, int employeeNumber)
{
	CCrewMember* crewMember = findCrewMemberByNumber(employeeNumber);
	if (!crewMember) {
		std::cerr << "Crew member with employee number " << employeeNumber << " not found." << std::endl;
		return false;
	}

	CFlight* flight = findFlightByNumber(flightNumber);
	if (!flight) {
		std::cerr << "Flight with number " << flightNumber << " not found." << std::endl;
		return false;
	}

	// Add crew member to flight using the + operator
	*flight = *flight + *crewMember;
	return true;
}

CPlane* CFlightCompany::getAircraftByIndex(int index)
{
	if (index < 0 || index >= static_cast<int>(numAircraft)) {
		std::cerr << "Invalid aircraft index: " << index << ". Valid range: 0-" << (numAircraft - 1) << std::endl;
		return nullptr;
	}

	return aircraft[index];
}

void CFlightCompany::Print(std::ostream& os) const{
	os << "Flight company: " << nameOfCompany << std::endl;
	os << "There are " << numCrewMembers << " Crew members:" << std::endl;
	for (std::size_t i = 0; i < numCrewMembers; i++) {
		os << "  " << *crewMembers[i] << std::endl;
	}
	os << "There are " << numAircraft << " Planes:" << std::endl;
	for (std::size_t i = 0; i < numAircraft; i++) {
		os << "  " << *aircraft[i] << std::endl;
	}
	os << "There are " << numFlights << " Flights:" << std::endl;
	for (std::size_t i = 0; i < numFlights; i++) {
		os << "  " << *flights[i] << std::endl;
	}

}

CPlane* CFlightCompany::GetPlane(int index)
{
	return getAircraftByIndex(index);
}

CCrewMember* CFlightCompany::findCrewMemberByNumber(int employeeNumber)
{
	for (std::size_t i = 0; i < numCrewMembers; i++) {
		if (crewMembers[i] && crewMembers[i]->getEmployeeNumber() == employeeNumber) {
			return crewMembers[i];
		}
	}
	return nullptr;
}

CFlight* CFlightCompany::findFlightByNumber(int flightNumber)
{
	for (std::size_t i = 0; i < numFlights; i++) {
		if (flights[i] && flights[i]->GetFlightNumber() == flightNumber) {
			return flights[i];
		}
	}
	return nullptr;
}