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
	CFlightInfo() = delete;
	CFlightInfo(std::string destination, int flightNumber, int timeOfFlight, int distance);
	CFlightInfo(const CFlightInfo& other);
	~CFlightInfo();

	//getters
	int GetFlightNumber() const;
	int GetFNum() const;
	std::string GetDest() const;
	int GetTimeOfFlight() const;
	int GetDistance() const;

	//setters
	bool SetFlightNumber(int flightNumber);
	bool SetDest(std::string destination);
	bool SetTimeOfFlight(int timeOfFlight);
	bool SetDistance(int distance);

	bool operator==(const CFlightInfo& other) const;
	CFlightInfo& operator=(const CFlightInfo& other);

	friend std::ostream& operator<<(std::ostream& os, const CFlightInfo& flightInfo);
	bool operator!=(const CFlightInfo& other) const;
	operator int() const;

	bool isValid(std::string destination, int flightNumber, int timeOfFlight, int distance);
	void setIfValid(std::string destination, int flightNumber, int timeOfFlight, int distance);

};
