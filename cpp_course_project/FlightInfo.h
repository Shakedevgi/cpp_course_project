#pragma once

#include <string>	
#include <iostream>


class CFlightInfo {
private:
	int flightNumber;
	std::string destination;
	int timeOfFlight;
	int distance;


public:
	//constructors
	CFlightInfo(std::string destination, int flightNumber, int timeOfFlight, int distance);
	CFlightInfo(const CFlightInfo& other);
	~CFlightInfo();

	//getters
	int GetFlightNumber() const;
	std::string GetDest() const;
	int GetTimeOfFlight() const;
	int GetDistance() const;

	//setters
	bool SetFlightNumber(int flightNumber);
	bool SetDest(std::string destination);
	bool SetTimeOfFlight(int timeOfFlight);
	bool SetDistance(int distance);

	bool IsEqual(const CFlightInfo& other) const;

	void Print() const;

	bool isValid(std::string destination, int flightNumber, int timeOfFlight, int distance);
	void setIfValid(std::string destination, int flightNumber, int timeOfFlight, int distance);

};
