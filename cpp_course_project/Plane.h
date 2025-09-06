#pragma once
#include <string>

class CPlane {
	static int nextSerial;     
	int serialNumber;         
	std::string model;
	int chairsNumber;

public:
	CPlane() = delete;  // deleting default c'tor
	CPlane(int chairsNumber, const std::string& model);
	CPlane(const CPlane& other);
	~CPlane();

	CPlane& operator=(const CPlane& other);

	bool operator==(const CPlane& other) const;

	friend std::ostream& operator<<(std::ostream& os, const CPlane& p);

	CPlane& operator++(); // postfix
	CPlane operator++(int); //prefix

	static bool isValid(int serial, const std::string& model, int chairs );
	void   setIfValid(int serial, int chairs, const std::string& model);

	int GetSerialNumber() const;
	const std::string& GetModel() const;
	int GetChairsNumber() const;
};