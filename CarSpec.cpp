#include "CarSpec.h"

CarSpec::CarSpec(std::string inputCarCompanyName, std::string inputCarModel, int inputCarYear, carColors inputCarColor,
	availabilityStatus inputCarAvailabilityStatus, float inputCarConditionScore, float inputCarPriceUSD, float inputCarRentUSD,
	float inputRentDiscountPercentage, float inputPriceDiscountPercentage, bool inputIsInsuredByCompany)
{
	//Checks if input strings have more than 32 characters
	if (inputCarCompanyName.length() > 32)
	{
		std::cerr << "Warning: Maximum of 32 characters allowed for Car Company Name.";
		
		//Cuts of characters after 32 characters
		carCompanyName.assign(inputCarCompanyName, 32);
	}
	
	carCompanyName.assign(inputCarCompanyName);

	//Checks if input strings have more than 32 characters
	if (inputCarModel.length() > 32)
	{
		std::cerr << "Warning: Maximum of 32 characters allowed for Car Model.";
		
		//Cuts of characters after 32 characters
		carModel.assign(inputCarModel, 32);
	}

	carModel.assign(inputCarModel);

	carYear = inputCarYear;
	carColor = inputCarColor;
	carAvailabilityStatus = inputCarAvailabilityStatus;
	carConditionScore = inputCarConditionScore;
	carPriceUSD = inputCarPriceUSD;
	carRentUSD = inputCarRentUSD;
	rentDiscountPercentage = inputRentDiscountPercentage;
	priceDiscountPercentage = inputPriceDiscountPercentage;
	isInsuredByCompany = inputIsInsuredByCompany;
}

bool CarSpec::operator==(CarSpec other)
{
	//Goes through each data memember to check if they are equal but if data memeber is null it ignores and still returns true 

	if (!carCompanyName.empty() && carCompanyName.compare(other.carCompanyName) != 0)
	{
		return false;
	}

	if (!carModel.empty() && carModel.compare(other.carModel) != 0)
	{
		return false;
	}

	if (carYear != NULL && carYear != other.carYear)
	{
		return false;
	}

	if (carColor != carColors::NA && carColor != other.carColor)
	{
		return false;
	}

	if (carAvailabilityStatus != availabilityStatus::NA && carAvailabilityStatus != other.carAvailabilityStatus)
	{
		return false;
	}

	if (carConditionScore != NULL && carConditionScore != other.carConditionScore)
	{
		return false;
	}

	if (carPriceUSD != NULL && carPriceUSD != other.carPriceUSD)
	{
		return false;
	}

	if (carRentUSD != NULL && carRentUSD != other.carRentUSD)
	{
		return false;
	}

	if (rentDiscountPercentage != NULL && rentDiscountPercentage != other.rentDiscountPercentage)
	{
		return false;
	}

	if (priceDiscountPercentage != NULL && priceDiscountPercentage != other.priceDiscountPercentage)
	{
		return false;
	}

	if (isInsuredByCompany != NULL && isInsuredByCompany != other.isInsuredByCompany)
	{
		return false;
	}

	return true;
}

bool CarSpec::isLessThan(CarSpec other, criteria inputCriteria)
{
	if (inputCriteria == criteria::carCompanyName)
	{
		return (carCompanyName.compare(other.carCompanyName) < 0);
	}

	if (inputCriteria == criteria::carModel)
	{
		return (carModel.compare(other.carModel) < 0);
	}

	if (inputCriteria == criteria::carYear)
	{
		return (carYear < other.carYear);
	}

	if (inputCriteria == criteria::carColor)
	{
		return (carColor < other.carColor);
	}

	if (inputCriteria == criteria::availabilityStatus)
	{
		return (carAvailabilityStatus < other.carAvailabilityStatus);
	}

	if (inputCriteria == criteria::carConditionScore)
	{
		return (carConditionScore < other.carConditionScore);
	}

	if (inputCriteria == criteria::carPriceUSD)
	{
		return (carPriceUSD < other.carPriceUSD);
	}

	if (inputCriteria == criteria::carRentUSD)
	{
		return (carRentUSD < other.carRentUSD);
	}

	if (inputCriteria == criteria::rentDiscountPercentage)
	{
		return (rentDiscountPercentage < other.rentDiscountPercentage);
	}

	if (inputCriteria == criteria::priceDiscountPercentage)
	{
		return (priceDiscountPercentage < other.priceDiscountPercentage);
	}

	exit(0);
}

void CarSpec::setCarCompanyName(std::string inputCarCompanyName)
{
	//Checks if input strings have more than 32 characters
	if (inputCarCompanyName.length() > 32)
	{
		std::cerr << "Warning: Maximum of 32 characters allowed for Car Company Name.";
		
		//Cuts of characters after 32 characters
		carCompanyName.assign(inputCarCompanyName, 32);
	}

	carCompanyName.assign(inputCarCompanyName);
}

std::string CarSpec::getCarCompanyName()
{
	return carCompanyName;
}

void CarSpec::setCarModel(std::string inputCarModel)
{
	//Checks if input strings have more than 32 characters
	if (inputCarModel.length() > 32)
	{
		std::cerr << "Warning: Maximum of 32 characters allowed for Car Model.";

		//Cuts of characters after 32 characters
		carModel.assign(inputCarModel, 32);
	}

	carModel.assign(inputCarModel);
}

std::string CarSpec::getCarModel()
{
	return carModel;
}

void CarSpec::setCarYear(int inputCarYear)
{
	carYear = inputCarYear;
}

int CarSpec::getCarYear()
{
	return carYear;
}

void CarSpec::setCarColor(carColors inputCarColor)
{
	carColor = inputCarColor;
}

carColors CarSpec::getCarColor()
{
	return carColor;
}

void CarSpec::setCarAvailabilityStatus(availabilityStatus inputCAvailabilityStatus)
{
	carAvailabilityStatus = inputCAvailabilityStatus;
}

availabilityStatus CarSpec::getCarAvailabilityStatus()
{
	return carAvailabilityStatus;
}

void CarSpec::setCarConditionScore(float inputCarConditionScore)
{
	carConditionScore = inputCarConditionScore;
}

float CarSpec::getCarConditionScore()
{
	return carConditionScore;
}

void CarSpec::setCarPriceUSD(float inputCarPriceUSD)
{
	carPriceUSD = inputCarPriceUSD;
}

float CarSpec::getCarPriceUSD()
{
	return carPriceUSD;
}

void CarSpec::setCarRentUSD(float inputCarRentUSD)
{
	carRentUSD = inputCarRentUSD;
}

float CarSpec::getCarRentUSD()
{
	return carRentUSD;
}

void CarSpec::setRentDiscountPercentage(float inputRentDiscountPercentage)
{
	rentDiscountPercentage = inputRentDiscountPercentage;
}

float CarSpec::getRentDiscountPercentage()
{
	return rentDiscountPercentage;
}

void CarSpec::setPriceDiscountPercentage(float inputPriceDiscountPercentage)
{
	priceDiscountPercentage = inputPriceDiscountPercentage;
}

float CarSpec::getPriceDiscountPercentage()
{
	return priceDiscountPercentage;
}

void CarSpec::setIsInsuredByCompany(bool inputIsInsuredByCompany)
{
	isInsuredByCompany = inputIsInsuredByCompany;
}

bool CarSpec::getIsInsuredByCompany()
{
	return isInsuredByCompany;
}

std::string CarSpec::carColorToString()
{
	//Current enum constants: red, blue, white, black, silver, NA

	if (carColor == carColors::red)
	{
		return "Red";
	}
	else if (carColor == carColors::blue)
	{
		return "Blue";
	}
	else if (carColor == carColors::white)
	{
		return "White";
	}
	else if (carColor == carColors::black)
	{
		return "Black";
	}
	else if (carColor == carColors::silver)
	{
		return "Silver";
	}
	else if (carColor == carColors::NA)
	{
		return "N/A";
	}

	return "ERROR";
}

std::string CarSpec::availabilityStatusToString()
{
	//Current enum constants: available, rented, sold, NA

	if (carAvailabilityStatus == availabilityStatus::available)
	{
		return "Available";
	}
	else if (carAvailabilityStatus == availabilityStatus::rented)
	{
		return "Rented";
	}
	else if (carAvailabilityStatus == availabilityStatus::sold)
	{
		return "Sold";
	}
	else if (carAvailabilityStatus == availabilityStatus::NA)
	{
		return "N/A";
	}

	return "ERROR";
}

void CarSpec::display()
{
	//to_string functions are necessary for ternary operator

	std::cout << "Car company name: " << (carCompanyName == "" ? "N/A" : carCompanyName);
	std::cout << "\nCar model: " << (carModel == "" ? "N/A" : carModel);
	std::cout << "\nCar year: " << (carYear == NULL ? "N/A" : std::to_string(carYear));
	std::cout << "\nCar color: " << carColorToString();
	std::cout << "\nCar availability status: " << availabilityStatusToString();
	std::cout << "\nCar condition score: " << (carConditionScore == 0 ? "N/A" : std::to_string(carConditionScore));
	std::cout << "\nCar price in USD: " << (carPriceUSD == 0 ? "N/A" : std::to_string(carPriceUSD));
	std::cout << "\nCar rent in USD: " << (carRentUSD == 0 ? "N/A" : std::to_string(carRentUSD));
	std::cout << "\nRent discount percentage: " << (rentDiscountPercentage == 0 ? "N/A" : std::to_string(rentDiscountPercentage));
	std::cout << "\nPrice discount percentage: " << (priceDiscountPercentage == 0 ? "N/A" : std::to_string(priceDiscountPercentage));
	std::cout << "\nIs insured by company: " << (isInsuredByCompany == true ? "Yes\n" : "No\n");
}