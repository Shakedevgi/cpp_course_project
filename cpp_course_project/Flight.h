#pragma once
#include <array>
#include<iostream>
#include "CrewMember.h"
#include "Plane.h"
#include "FlightInfo.h"
#include "Constants.h"
class CFlight {
private:
	CFlightInfo flightInfo;
	CPlane plane;
    bool hasPlane;
    CCrewMember* crewMembers[MAX_CREW];
    std::size_t numOfCrewMembers;
	
    bool hasCrewByName(const std::string& name) const;

    public:
    CFlight() = delete;
    CFlight(const CFlightInfo& flightInfo);
    CFlight(const CFlightInfo& flightInfo, const CPlane& plane);
    CFlight(const CFlight& other);
    ~CFlight();
    
    CFlight& operator=(const CFlight& other);
    void updatePlane(const CPlane& plane);
    void SetPlane(const CPlane& plane);
    CFlight& operator+(CCrewMember& crewMember);
    bool operator==(const CFlight& other) const;
    friend std::ostream& operator<<(std::ostream& os, const CFlight& flight);
    
    // Getter method for flight number
    int GetFlightNumber() const;
};
