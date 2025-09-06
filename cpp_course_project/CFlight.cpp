#include "Flight.h"
#include <iostream>
#include "Constants.h"

bool CFlight::hasCrewByName(const std::string& name) const{
    for (std::size_t i = 0; i < numOfCrewMembers; i++){
        if (crewMembers[i] && crewMembers[i]->GetName() == name) {return true;}
    }
    return false;
}

CFlight::CFlight(const CFlightInfo& flightInfo) : flightInfo(flightInfo), plane(0,""), hasPlane(false), numOfCrewMembers(0){
    for (std::size_t i = 0; i < MAX_CREW; i++){
        crewMembers[i] = nullptr;
    }
}

CFlight::CFlight(const CFlightInfo& flightInfo, const CPlane& plane) : flightInfo(flightInfo), plane(plane), hasPlane(true), numOfCrewMembers(0){
    for (std::size_t i = 0; i < MAX_CREW; i++){
        crewMembers[i] = nullptr;
    }
}

void CFlight::updatePlane(const CPlane& newPlane){
    plane = newPlane;
    hasPlane = true;
}

void CFlight::SetPlane(const CPlane& newPlane){
    updatePlane(newPlane);
}

CFlight& CFlight::operator+(CCrewMember& crewMember){
    if(numOfCrewMembers >= MAX_CREW){
        std::cerr << "Max crew members reached" << std::endl;
        return *this;
    }
    if(hasCrewByName(crewMember.GetName())){
        std::cerr << "Crew member already exists" << std::endl;
        return *this;
    }
    crewMembers[numOfCrewMembers++] = &crewMember;
    return *this;
}

bool CFlight::operator==(const CFlight& other) const{
    return flightInfo == other.flightInfo;
}

std::ostream& operator<<(std::ostream& os, const CFlight& flight){
    os << "Flight Info: " << flight.flightInfo << std::endl;
    if (flight.hasPlane) {
        os << "Plane: " << flight.plane << std::endl;
    } else {
        os << "No plane assign yet";
    }
    os << "There are " << flight.numOfCrewMembers << " crew members in flight:" << std::endl;
    for (std::size_t i = 0; i < flight.numOfCrewMembers; i++){
        os << *flight.crewMembers[i] << std::endl;
    }
    return os;
}

CFlight::CFlight(const CFlight& other) : flightInfo(other.flightInfo), plane(other.plane), hasPlane(other.hasPlane), numOfCrewMembers(other.numOfCrewMembers)
{
    for (std::size_t i = 0; i < MAX_CREW; i++){
        crewMembers[i] = other.crewMembers[i];
    }
}

CFlight::~CFlight()
{
    // Note: We don't delete crewMembers as they are pointers to external objects
}

CFlight& CFlight::operator=(const CFlight& other)
{
    if (this != &other) {
        flightInfo = other.flightInfo;
        plane = other.plane;
        hasPlane = other.hasPlane;
        numOfCrewMembers = other.numOfCrewMembers;
        for (std::size_t i = 0; i < MAX_CREW; i++){
            crewMembers[i] = other.crewMembers[i];
        }
    }
    return *this;
}

int CFlight::GetFlightNumber() const
{
    return flightInfo.GetFlightNumber();
}