#pragma once

#include <string>
#include <iostream>

class CFlightCompany {
private:
	std::string nameOfCompany;

public:
	CFlightCompany(const std::string& name);
	CFlightCompany(const CFlightCompany& other);
	~CFlightCompany();

	std::string GetName() const;

	bool SetName(const std::string& name);

	void Print() const;

	bool isValid(const std::string& name);

};