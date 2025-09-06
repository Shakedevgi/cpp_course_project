// ===== CCrewMember.h =====
#pragma once
#include <string>
#include "Address.h"

class CCrewMember {
    std::string name;
    int         airTime;
    CAddress    address;
    const int   employeeNumber;
    static int  nextEmployeeNumber;

public:
    CCrewMember() = delete;

    // Keep only TWO ctors to avoid ambiguity:
    // 1) With address (airTime optional at the END)
    CCrewMember(const std::string& name, const CAddress& address, int airTime = 0);

    // 2) Without address (airTime optional) – will set a valid default address internally
    explicit CCrewMember(const std::string& name, int airTime = 0);

    static const int START_ID = 1000;

    CCrewMember(const CCrewMember& other);
    ~CCrewMember();

    static bool isValid(const std::string& name, int airTime, const CAddress& address);

    friend std::ostream& operator<<(std::ostream& os, const CCrewMember& crewMember);

    const std::string& GetName() const;
    int  GetAirTime() const;
    const CAddress& GetAddress() const;

    bool SetAddress(const CAddress& newAddress);
    bool Setname(const std::string& newName);
    void UpdateAddress(const CAddress& newAddress);

    bool operator==(const CCrewMember& other) const;
    CCrewMember& operator=(const CCrewMember& other);
    bool operator!() const;

    int getEmployeeNumber() const;

    CCrewMember& operator+=(int minutes);
};
