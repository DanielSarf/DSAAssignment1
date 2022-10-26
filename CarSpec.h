#pragma once

#include <iostream>
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

	//When displaying data, enums need to be represented using strings describing them
	std::string carColorToString();
	std::string availabilityStatusToString();

public:
	//Parameterized Contructor allows objects to be made with missing information or can be used to make search queries using a non-member function
	CarSpec(std::string inputCarCompanyName = "", std::string inputCarModel = "", int inputCarYear = NULL, carColors inputCarColor = carColors::NA,
		availabilityStatus inputCarAvailabilityStatus = availabilityStatus::NA, float inputCarConditionScore = NULL, float inputCarPriceUSD = NULL, float inputCarRentUSD = NULL,
		float inputRentDiscountPercentage = NULL, float inputPriceDiscountPercentage = NULL, bool inputIsInsuredByCompany = NULL);

	//Customized operator equality operator that ignores missing information (useful to display objects of a certain type)
	bool operator==(CarSpec);

	bool isEqualCRITERIA(CarSpec other, criteria inputCriteria);

	bool isLessThan(CarSpec other, criteria inputCriteria);

	bool isLessThanOrEqual(CarSpec other, criteria inputCriteria);

	bool isGreaterThan(CarSpec other, criteria inputCriteria);

	bool isGreaterThanOrEqual(CarSpec other, criteria inputCriteria);

	//Setter getter functions:
	void setCarCompanyName(std::string inputCarCompanyName);
	std::string getCarCompanyName();

	void setCarModel(std::string inputCarModel);
	std::string getCarModel();

	void setCarYear(int inputCarYear);
	int getCarYear();

	void setCarColor(carColors inputCarColor);
	carColors getCarColor();

	void setCarAvailabilityStatus(availabilityStatus inputCarAvailabilityStatus);
	availabilityStatus getCarAvailabilityStatus();

	void setCarConditionScore(float inputCarConditionScore);
	float getCarConditionScore();

	void setCarPriceUSD(float inputCarPriceUSD);
	float getCarPriceUSD();

	void setCarRentUSD(float inputCarRentUSD);
	float getCarRentUSD();

	void setRentDiscountPercentage(float inputRentDiscountPercentage);
	float getRentDiscountPercentage();

	void setPriceDiscountPercentage(float inputPriceDiscountPercentage);
	float getPriceDiscountPercentage();

	void setIsInsuredByCompany(bool inputIsInsuredByCompany);
	bool getIsInsuredByCompany();

	bool isDataMemberEqual(criteria inputCriteria);

	//Display function outputs to console in a neat format
	void display();
};