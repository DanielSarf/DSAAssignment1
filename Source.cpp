#include <iostream>
#include <windows.h>

#include "SLList.h"

using namespace std;

int randomNumber(int min, int max)
{

	return min + rand() % (max - min + 1);
}

SLList contructObject()
{
	return SLList("file.bin");
}

SLList contructSearchObject()
{
	return SLList("file.bin");
}

void displayCarsOfType(CarSpec searchObject, SLList* list)
{

}

int returnCountOfList(SLList* list)
{
	return 0;
}

SLList sortList(SLList list, criteria sortingCriteria, bool ascendingOrder)
{
	if (list.getLength() == 1)
	{
		return list;
	}

	int t1 = list.getLength() / 2;
	int t2 = list.getLength() - t1;

	SLList t1List, t2List;

	for (int i = 0; i < t1; i++)
	{
		t1List.insertEnd(list.findNodePOS(i)->getData());
	}

	for (int i = t1; i < list.getLength(); i++)
	{
		t1List.insertEnd(list.findNodePOS(i)->getData());
	}

	t1List = sortList(t1List, sortingCriteria, ascendingOrder);
	t2List = sortList(t2List, sortingCriteria, ascendingOrder);

	if (ascendingOrder)
	{
		for (int i = 0, iT1 = 0, iT2 = 0; i < list.getLength(); i++)
		{
			if ((t1List.findNodePOS(iT1)->getData().isLessThanOrEqual(t2List.findNodePOS(iT2)->getData(), sortingCriteria) && iT1 != t1) || iT2 == t2)
			{
				list.replaceNodePOS(i, t1List.findNodePOS(iT1)->getData());
				iT1++;
			}
			else if ((t2List.findNodePOS(iT2)->getData().isLessThanOrEqual(t1List.findNodePOS(iT1)->getData(), sortingCriteria) && iT2 != t2) || iT1 == t1)
			{
				list.replaceNodePOS(i, t2List.findNodePOS(iT2)->getData());
				iT2++;
			}
		}
	}
	else
	{
		for (int i = 0, iT1 = 0, iT2 = 0; i < list.getLength(); i++)
		{
			if ((t1List.findNodePOS(iT1)->getData().isLessThanOrEqual(t2List.findNodePOS(iT2)->getData(), sortingCriteria) && iT1 != t1) || iT2 == t2)
			{
				list.replaceNodePOS(i, t1List.findNodePOS(iT1)->getData());
				iT1++;
			}
			else if ((t2List.findNodePOS(iT2)->getData().isLessThanOrEqual(t1List.findNodePOS(iT1)->getData(), sortingCriteria) && iT2 != t2) || iT1 == t1)
			{
				list.replaceNodePOS(i, t2List.findNodePOS(iT2)->getData());
				iT2++;
			}
		}
	}

	return list;
}

void displayItemsAscending(SLList list, criteria sortingCriteria)
{
	SLList sortedList = sortList(list, sortingCriteria, true);

	sortedList.displayAllADT();
}

void displayItemsDescending(SLList list, criteria sortingCriteria)
{
	SLList sortedList = sortList(list, sortingCriteria, false);

	sortedList.displayAllADT();
}

void populateList(SLList& list, int numberOfObjects)
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

int main()
{
	srand((unsigned int)time(NULL));

	SLList Test("file.bin");

	populateList(Test, 100);

	Test.displayAllADT();

	return 0;
}