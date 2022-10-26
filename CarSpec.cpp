#include "CarSpec.h"

CarSpec::CarSpec(std::string inputCarCompanyName, std::string inputCarModel, int inputCarYear, carColors inputCarColor,
	availabilityStatus inputCarAvailabilityStatus, float inputCarConditionScore, float inputCarPriceUSD, float inputCarRentUSD,
	float inputRentDiscountPercentage, float inputPriceDiscountPercentage, bool inputIsInsuredByCompany)
{
	//Checks if input string has more than 32 characters
	if (inputCarCompanyName.length() > 32)
	{
		std::cerr << "Warning: Maximum of 32 characters allowed for Car Company Name\n";

		//Cuts of characters after 32 characters
		strcpy_s(carCompanyName, inputCarCompanyName.substr(0, 32).c_str());
	}
	else
	{
		//If input string has 32 characters or less
		strcpy_s(carCompanyName, inputCarCompanyName.c_str());

		//Fills remaining characters with upto 32 ' ' (to be used as a  delimiter) if characters are less than 32
		for (int i = inputCarCompanyName.length(); i < 32; i++)
		{
			carCompanyName[i] = ' ';
		}

		//Sets last char to null character
		carCompanyName[32] = '\0';
	}

	//Checks if input string has more than 32 characters
	if (inputCarModel.length() > 32)
	{
		std::cerr << "Warning: Maximum of 32 characters allowed for Car Model\n";

		//Cuts of characters after 32 characters
		strcpy_s(carModel, (inputCarModel.substr(0, 32).c_str()));
	}
	else
	{
		//If input string has 32 characters or less
		strcpy_s(carModel, inputCarModel.c_str());

		//Fills remaining characters with upto 32 ' ' (to be used as a  delimiter) if characters are less than 32
		for (int i = inputCarModel.length(); i < 32; i++)
		{
			carModel[i] = ' ';
		}

		//Sets last char to null character
		carModel[32] = '\0';
	}

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

	if (!(strlen(carCompanyName) == 0) && strcmp(carCompanyName, other.carCompanyName) != 0)
	{
		return false;
	}

	if (!(strlen(carModel) == 0) && strcmp(carModel, other.carModel) != 0)
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
		return (strcmp(carCompanyName, other.carCompanyName) < 0);
	}

	if (inputCriteria == criteria::carModel)
	{
		return (strcmp(carModel, other.carModel) < 0);
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

bool CarSpec::isLessThanOrEqual(CarSpec other, criteria inputCriteria)
{
	return (isLessThan(other, inputCriteria) || (*this) == other);
}

bool CarSpec::isGreaterThan(CarSpec other, criteria inputCriteria)
{
	return (other.isLessThan(*this, inputCriteria));
}

bool CarSpec::isGreaterThanOrEqual(CarSpec other, criteria inputCriteria)
{
	return (isGreaterThan(other, inputCriteria) || (*this) == other);
}

void CarSpec::setCarCompanyName(std::string inputCarCompanyName)
{
	//Checks if input string has more than 32 characters
	if (inputCarCompanyName.length() > 32)
	{
		std::cerr << "Warning: Maximum of 32 characters allowed for Car Company Name\n";

		//Cuts of characters after 32 characters
		strcpy_s(carCompanyName, inputCarCompanyName.substr(0, 32).c_str());
	}
	else
	{
		//If input string has 32 characters or less
		strcpy_s(carCompanyName, inputCarCompanyName.c_str());

		//Fills remaining characters with upto 32 ' ' (to be used as a  delimiter) if characters are less than 32
		for (int i = inputCarCompanyName.length(); i < 32; i++)
		{
			carCompanyName[i] = ' ';
		}

		//Sets last char to null character
		carCompanyName[32] = '\0';
	}
}

std::string CarSpec::getCarCompanyName()
{
	for (int indexOfLastSpaceDelimiter = 31; indexOfLastSpaceDelimiter >= 0; indexOfLastSpaceDelimiter--)
	{
		if (carCompanyName[indexOfLastSpaceDelimiter] != ' ')
		{
			return (std::string(carCompanyName).substr(0, indexOfLastSpaceDelimiter + 1));
		}
	}

	return std::string(carCompanyName);
}

void CarSpec::setCarModel(std::string inputCarModel)
{
	//Checks if input string has more than 32 characters
	if (inputCarModel.length() > 32)
	{
		std::cerr << "Warning: Maximum of 32 characters allowed for Car Model\n";

		//Cuts of characters after 32 characters
		strcpy_s(carModel, (inputCarModel.substr(0, 32).c_str()));
	}
	else
	{
		//If input string has 32 characters or less
		strcpy_s(carModel, inputCarModel.c_str());

		//Fills remaining characters with upto 32 ' ' (to be used as a  delimiter) if characters are less than 32
		for (int i = inputCarModel.length(); i < 32; i++)
		{
			carModel[i] = ' ';
		}

		//Sets last char to null character
		carModel[32] = '\0';
	}
}

std::string CarSpec::getCarModel()
{
	for (int indexOfLastSpaceDelimiter = 31; indexOfLastSpaceDelimiter >= 0; indexOfLastSpaceDelimiter--)
	{
		if (carModel[indexOfLastSpaceDelimiter] != ' ')
		{
			return (std::string(carModel).substr(0, indexOfLastSpaceDelimiter + 1));
		}
	}

	return std::string(carModel);
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

	std::cout << "Car company name: " << (getCarCompanyName() == "" ? "N/A" : getCarCompanyName());
	std::cout << "\nCar model: " << (getCarModel() == "" ? "N/A" : getCarModel());
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