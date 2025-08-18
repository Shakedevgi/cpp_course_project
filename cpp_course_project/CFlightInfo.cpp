#include "FlightInfo.h"


bool CFlightInfo::isValid(std::string destination, int flightNumber, int timeOfFlight, int distance)
{
	return flightNumber > 0 && !destination.empty() && timeOfFlight > 0 && distance > 0;
}

void CFlightInfo::setIfValid(std::string destination, int flightNumber, int timeOfFlight, int distance)
{
	if (isValid(destination, flightNumber, timeOfFlight, distance)) {
		this->flightNumber = flightNumber;
		this->destination = destination;
		this->timeOfFlight = timeOfFlight;
		this->distance = distance;
	}
	else {

		std::cerr << "Invalid CFlightInfo data.\n";
	}
}

CFlightInfo::CFlightInfo(std::string destination, int flightNumber, int timeOfFlight, int distance)
{
	setIfValid(destination, flightNumber, timeOfFlight, distance);
}

CFlightInfo::CFlightInfo(const CFlightInfo& other)
{
	this->flightNumber = other.flightNumber;
	this->destination = other.destination;
	this->timeOfFlight = other.timeOfFlight;
	this->distance = other.distance;
}

CFlightInfo::~CFlightInfo()
{}

int CFlightInfo::GetFlightNumber() const { return flightNumber; }

std::string CFlightInfo::GetDest() const { return destination; }

int CFlightInfo::GetTimeOfFlight() const { return timeOfFlight; }

int CFlightInfo::GetDistance() const { return distance; }

bool CFlightInfo::SetFlightNumber(int flightNumber)
{
	if (flightNumber <= 0) { return false; }
	this->flightNumber = flightNumber;
	return true;
}

bool CFlightInfo::SetDest(std::string destination)
{
	if (destination.empty()) { return false; }
	this->destination = destination;
	return true;
}

bool CFlightInfo::SetTimeOfFlight(int timeOfFlight)
{
	if (timeOfFlight <= 0) { return false; }
	this->timeOfFlight = timeOfFlight;
	return true;
}

bool CFlightInfo::SetDistance(int distance)
{
	if (distance <= 0) { return false; }
	this->distance = distance;
	return true;
}

bool CFlightInfo::IsEqual(const CFlightInfo& other) const
{
	return this->flightNumber == other.flightNumber;
}

void CFlightInfo::Print() const
{
	std::cout << "Flight Info dest: " << destination << " Number " << flightNumber << " minutes " << timeOfFlight << " KM " << distance << std::endl;
}
