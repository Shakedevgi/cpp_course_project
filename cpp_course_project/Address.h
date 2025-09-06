#pragma once
#include <string>

class CAddress {
	std::string city;
	std::string street;
	int houseNumber;

	
public:
	CAddress() = delete; // default constructor is deleted
	CAddress(int houseNumber, const std::string & street,  const std::string& city = "Tel Aviv");
	CAddress(int houseNumber, const char* street, const char* city);
	CAddress(const CAddress& other);
	~CAddress();
	
	friend std::ostream& operator<<(std::ostream& os, const CAddress& address);
	friend std::istream& operator>>(std::istream& is, CAddress& address);
	bool operator==(const CAddress& other) const;
	bool operator!=(const CAddress& other) const;
	CAddress& operator=(const CAddress& other);

	static bool isValid(const std::string& c, const std::string& s, int h);
	void setIfValid(const std::string& c, const std::string& s, int h);

	const std::string& GetCity () const;
	const std::string& GetStreet () const;
	int GetHouseNumber() const;
	void UpdateAddress(const std::string& newCity, const std::string& newStreet, int newHouseNumber);
	std::string GetCurrentAddress() const;
};