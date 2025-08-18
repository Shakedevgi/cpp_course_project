#pragma once
#include <string>
#include "Address.h"
class CCrewMember {
	std::string name;
	int airTime;
	CAddress address;

public:
	CCrewMember(const std::string& name, const CAddress& address, int airTime = 0);
	CCrewMember(const CCrewMember& other);
	~CCrewMember();

	static bool isValid(const std::string& name, int airTime, const CAddress& address);

	void Print() const;
	const std::string& GetName() const;
	int GetAirTime() const;
	bool UpdateMinutes(int minutes);
	const CAddress& GetAddress() const;
	bool SetAddress(const CAddress& newAddress);
	bool Setname(const std::string& newName);
	void UpdateAddress(const CAddress& newAddress);
	bool IsEqual(const CCrewMember& other) const;
};