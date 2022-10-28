#include <iostream>
#include <time.h>

#include "SLList.h"

using namespace std;

int randomNumber(int min, int max);

void searchInCriteriaAndDisplay(SLList& list, int matchWith, criteria displayCriteria);

int returnCountOfList(SLList& list);

template <typename T>
int countOfCriteria(SLList& list, T matchWith, criteria countCriteria);

void sortList(SLList& list, criteria sortingCriteria, bool ascendingOrder);

void displayItemsAscending(SLList& list, criteria sortingCriteria);

void displayItemsDescending(SLList& list, criteria sortingCriteria);

void populateList(SLList& list, int numberOfObjects);

int main()
{
	srand((unsigned int)time(NULL));

	SLList Test;

	populateList(Test, 100);

	Test.displayAll();

	return 0;
}

int randomNumber(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void searchInCriteriaAndDisplay(SLList& list, int matchWith, criteria displayCriteria)
{
	////Goes through list and displays 

	//SLLNode* p = list.getHead();

	//int counter = 0;

	//while (p != nullptr)
	//{
	//	/*if(p->getData().isEqualCRITERIA())
	//	std::cout << "Data at Position " << counter << ":\n";
	//	p->getData().display();
	//	std::cout << "\n";*/

	//	counter++;
	//	p = p->getNext();
	//}
}

int returnCountOfList(SLList& list) //DONE
{
	SLLNode* p = list.getHead();

	int count = 0;

	while (p != nullptr)
	{
		count++;
		p = p->getNext();
	}

	return count;
}

template <typename T>
int countOfCriteria(SLList& list, T matchWith, criteria countCriteria) //DONE
{
	SLLNode* p = list.getHead();

	int count = 0;

	CarSpec data;

	while (p != nullptr)
	{
		data = p->getData();

		if ((p->getData().isDataMemberEqual(matchWith, countCriteria)))
		{
			count++;
		}

		p = p->getNext();
	}

	return count;
}

void sortList(SLList& list, criteria sortingCriteria, bool ascendingOrder)
{
	//Alright boys we'll have to think in powers of 2 i.e. 1, 2, 4, 8 etc.

	int listLength = list.getLength();

	if (listLength <= 1)
	{
		return;
	}

	int stepSize = 1;
	while (stepSize < listLength)
	{

	}
}

void displayItemsAscending(SLList& list, criteria sortingCriteria) //Done
{
	SLList tempList = list;

	sortList(tempList, sortingCriteria, true);

	tempList.displayAll();
}

void displayItemsDescending(SLList& list, criteria sortingCriteria) //Done
{
	SLList tempList = list;

	sortList(tempList, sortingCriteria, false);

	tempList.displayAll();
}

void populateList(SLList& list, int numberOfObjects) //Done
{
	//Function creats CarSpec objects by randomly choosing available options, then inserts them into list

	string carCompanyName;//  Honda, Toyota, Suzuki, BMW
	string carModel;// Sedan Accord Civic, Avalon Corolla Prius, Alto Swift Mehran, 1 Series 2 Series 3 Series
	int carYear;// from 2010 to 2022
	carColors carColor;// from 0 to 4
	availabilityStatus carAvailabilityStatus;// from 0 to 2
	float carConditionScore;// from 500 to 1000
	float carPriceUSD;// from 8000 to 25000
	float carRentUSD;// from 80 to 300
	float rentDiscountPercentage;// from 0 to 30
	float priceDiscountPercentage;// from 0 to 20
	bool isInsuredByCompany;// from 0 to 1

	for (int i = 0; i < numberOfObjects; i++)
	{
		int currentRandomNumber = randomNumber(1, 4);

		if (currentRandomNumber == 1)
		{
			carCompanyName.assign("Honda");

			currentRandomNumber = randomNumber(1, 3);

			if (currentRandomNumber == 1)
			{
				carModel.assign("Sedan");
			}
			else if (currentRandomNumber == 2)
			{
				carModel.assign("Accord");
			}
			else if (currentRandomNumber == 3)
			{
				carModel.assign("Civic");
			}
		}
		else if (currentRandomNumber == 2)
		{
			carCompanyName.assign("Toyota");

			currentRandomNumber = randomNumber(1, 3);

			if (currentRandomNumber == 1)
			{
				carModel.assign("Avalon");
			}
			else if (currentRandomNumber == 2)
			{
				carModel.assign("Corolla");
			}
			else if (currentRandomNumber == 3)
			{
				carModel.assign("Prius");
			}
		}
		else if (currentRandomNumber == 3)
		{
			carCompanyName.assign("Suzuki");

			currentRandomNumber = randomNumber(1, 3);

			if (currentRandomNumber == 1)
			{
				carModel.assign("Alto");
			}
			else if (currentRandomNumber == 2)
			{
				carModel.assign("Swift");
			}
			else if (currentRandomNumber == 3)
			{
				carModel.assign("Mehran");
			}
		}
		else if (currentRandomNumber == 4)
		{
			carCompanyName.assign("BMW");

			currentRandomNumber = randomNumber(1, 3);

			if (currentRandomNumber == 1)
			{
				carModel.assign("1 Series");
			}
			else if (currentRandomNumber == 2)
			{
				carModel.assign("2 Series");
			}
			else if (currentRandomNumber == 3)
			{
				carModel.assign("3 Series");
			}
		}

		carYear = randomNumber(2010, 2022);

		carColor = (carColors)randomNumber(0, 4);

		carAvailabilityStatus = (availabilityStatus)randomNumber(0, 2);

		carConditionScore = (float)randomNumber(500, 1000);

		carPriceUSD = (float)randomNumber(8000, 25000);

		carRentUSD = (float)randomNumber(80, 300);

		rentDiscountPercentage = (float)randomNumber(0, 30);

		priceDiscountPercentage = (float)randomNumber(0, 20);

		isInsuredByCompany = (bool)randomNumber(0, 1);

		list.insertEnd(CarSpec(carCompanyName, carModel, carYear, carColor,
			carAvailabilityStatus, carConditionScore, carPriceUSD, carRentUSD,
			rentDiscountPercentage, priceDiscountPercentage, isInsuredByCompany));
	}
}