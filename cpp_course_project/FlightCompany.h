#pragma once

#include <string>
#include <iostream>
#include "CrewMember.h"
#include "Plane.h"
#include "Flight.h"
#include "Constants.h"

class CFlightCompany {
private:
	std::string nameOfCompany;
	CCrewMember* crewMembers[MAX_CREWS];
	CPlane* aircraft[MAX_PLANES];
	CFlight* flights[MAX_FLIGHT];
	std::size_t numCrewMembers;
	std::size_t numAircraft;
	std::size_t numFlights;

public:
	CFlightCompany(const std::string& name);
	CFlightCompany(const CFlightCompany& other) = delete; // Disallow copying as per requirements
	~CFlightCompany();

	// Assignment operator (declared but not implemented as per requirements)
	CFlightCompany& operator=(const CFlightCompany& other) = delete;

	std::string GetName() const;
	bool SetName(const std::string& name);
	friend std::ostream& operator<<(std::ostream& os, const CFlightCompany& company);
	bool isValid(const std::string& name);
	void Print(std::ostream& os) const;


	// Required methods for managing crew, aircraft, and flights
	bool AddCrewMember(const CCrewMember& crewMember);
	bool AddPlane(const CPlane& plane);
	bool AddFlight(const CFlight& flight);
	bool AddCrewToFlight(int flightNumber, int employeeNumber);
	CPlane* getAircraftByIndex(int index);
	CPlane* GetPlane(int index);

	// Helper functions
	CCrewMember* findCrewMemberByNumber(int employeeNumber);
	CFlight* findFlightByNumber(int flightNumber);

};