#include "FlightInfo.h"


bool CFlightInfo::isValid(std::string destination, int flightNumber, int timeOfFlight, int distance)
{
	return flightNumber > 0 && !destination.empty() && timeOfFlight > 0 && distance > 0;
}

void CFlightInfo::setIfValid(std::string destination, int flightNumber, int timeOfFlight, int distance)
{
	if (isValid(destination, flightNumber, timeOfFlight, distance)) {
		SetFlightNumber(flightNumber);
		SetDest(destination);
		SetTimeOfFlight(timeOfFlight);
		SetDistance(distance);
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

int CFlightInfo::GetFNum() const { return flightNumber; }

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

bool CFlightInfo::operator==(const CFlightInfo& other) const{
	return this->flightNumber == other.flightNumber;
}

bool CFlightInfo::operator!=(const CFlightInfo& other) const{
	return !(*this == other);
}

CFlightInfo::operator int() const{
	return timeOfFlight;
}


std::ostream& operator<<(std::ostream& os, const CFlightInfo& flightInfo){
	os << "Flight Info dest: " << flightInfo.destination << " Number " << flightInfo.flightNumber << " minutes " << flightInfo.timeOfFlight << " KM " << flightInfo.distance << std::endl;
	return os;
}

CFlightInfo& CFlightInfo::operator=(const CFlightInfo& other)
{
	if (this != &other) {
		this->flightNumber = other.flightNumber;
		this->destination = other.destination;
		this->timeOfFlight = other.timeOfFlight;
		this->distance = other.distance;
	}
	return *this;
}
