#pragma once

#include <iostream>
#include <cstring>
#include <string>

enum class carColors
{
	red, blue, white, black, silver, NA
};

enum class availabilityStatus
{
	available, rented, sold, NA
};

enum class criteria
{
	carCompanyName, carModel, carYear, carColor, availabilityStatus, carConditionScore,
	carPriceUSD, carRentUSD, rentDiscountPercentage, priceDiscountPercentage, isInsuredByCompany
};

//This ADT is meant to store Car information typically found in Car Dealerships
class CarSpec
{
private:
	char carCompanyName[33];
	char carModel[33];
	int carYear;
	carColors carColor;
	availabilityStatus carAvailabilityStatus;
	float carConditionScore;
	float carPriceUSD;
	float carRentUSD;
	float rentDiscountPercentage;
	float priceDiscountPercentage;
	bool isInsuredByCompany;

public:
	//Parameterized Contructor allows objects to be made with missing information or can be used to make search queries using a non-member function
	CarSpec(std::string inputCarCompanyName = "", std::string inputCarModel = "", int inputCarYear = NULL, carColors inputCarColor = carColors::NA,
		availabilityStatus inputCarAvailabilityStatus = availabilityStatus::NA, float inputCarConditionScore = NULL, float inputCarPriceUSD = NULL, float inputCarRentUSD = NULL,
		float inputRentDiscountPercentage = NULL, float inputPriceDiscountPercentage = NULL, bool inputIsInsuredByCompany = NULL);

	//Customized operator equality operator
	bool operator==(CarSpec) const;

	bool isEqualCRITERIA(CarSpec other, criteria inputCriteria) const;
	bool isLessThanCRITERIA(CarSpec other, criteria inputCriteria) const;
	bool isLessThanOrEqualCRITERIA(CarSpec other, criteria inputCriteria) const;
	bool isGreaterThanCRITERIA(CarSpec other, criteria inputCriteria) const;
	bool isGreaterThanOrEqualCRITERIA(CarSpec other, criteria inputCriteria) const;

	//Setter getter functions:
	void setCarCompanyName(std::string inputCarCompanyName);
	std::string getCarCompanyName() const;

	void setCarModel(std::string inputCarModel);
	std::string getCarModel() const;

	void setCarYear(int inputCarYear);
	int getCarYear() const;

	void setCarColor(carColors inputCarColor);
	carColors getCarColor() const;

	void setCarAvailabilityStatus(availabilityStatus inputCarAvailabilityStatus);
	availabilityStatus getCarAvailabilityStatus() const;

	void setCarConditionScore(float inputCarConditionScore);
	float getCarConditionScore() const;

	void setCarPriceUSD(float inputCarPriceUSD);
	float getCarPriceUSD() const;

	void setCarRentUSD(float inputCarRentUSD);
	float getCarRentUSD() const;

	void setRentDiscountPercentage(float inputRentDiscountPercentage);
	float getRentDiscountPercentage() const;

	void setPriceDiscountPercentage(float inputPriceDiscountPercentage);
	float getPriceDiscountPercentage() const;

	void setIsInsuredByCompany(bool inputIsInsuredByCompany);
	bool getIsInsuredByCompany() const;

	template<typename T>
	bool isDataMemberEqual(T matchWith, criteria inputCriteria) const;
	
	//When displaying data, enums need to be represented using strings describing them
	std::string carColorToString() const;
	std::string availabilityStatusToString() const;

	//Outputs to stream in a neat format
	friend std::ostream& operator<<(std::ostream& os, const CarSpec& object);
};