#pragma once
#include <string>

class CAddress {
	std::string city;
	std::string street;
	int houseNumber;

	
public:
	CAddress(int houseNumber, const std::string & street,  const std::string& city = "Tel Aviv");
	CAddress(const CAddress& other);
	~CAddress();
	
	static bool isValid(const std::string& c, const std::string& s, int h);
	void setIfValid(const std::string& c, const std::string& s, int h);

	void Print() const;
	const std::string& GetCity () const;
	const std::string& GetStreet () const;
	int GetHouseNumber() const;
	void UpdateAddress(const std::string& newCity, const std::string& newStreet, int newHouseNumber);
};