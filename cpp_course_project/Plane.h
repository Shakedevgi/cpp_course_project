#pragma once
#include <string>

class CPlane {
	int serialNumber;
	std::string model;
	int chairsNumber;

public:
	CPlane(int serialNumber, int chairsNumber, const std::string& model);
	CPlane(const CPlane& other);
	~CPlane();

	static bool isValid(int serial, int chairs, const std::string& model);
	void   setIfValid(int serial, int chairs, const std::string& model);

	void Print() const;
	int GetSerialNumber() const;
	const std::string& GetModel() const;
	int GetChairsNumber() const;
	bool IsEqual(const CPlane& other) const;
};
