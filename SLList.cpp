#include "SLList.h"

SLList::SLList(std::string inputFileName)
{
	//Sets head and tail to nullptr
	head = nullptr;
	tail = nullptr;

	fileName.assign(inputFileName);

	length = 0;

	std::ifstream inputFile;

	inputFile.open(fileName);

	//If file exists, import from it
	if (inputFile)
	{
		inputFile.close();

		importData();
	}
	//If file does not exist, create and write validation key to it
	else
	{
		inputFile.close();

		std::ofstream outputFile;
		outputFile.open(fileName);

		std::string validationString = "SLLFileForCarSpec";

		outputFile << validationString;

		outputFile.close();
	}
}

SLList::SLList()
{
	//Sets head and tail to nullptr
	head = nullptr;
	tail = nullptr;

	fileName.assign("");

	length = 0;
}

bool SLList::isEmpty()
{
	return (length == 0);
}

int SLList::getLength()
{
	return length;
}

void  SLList::setHead(SLLNode* inputHead)
{
	head = inputHead;

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

SLLNode* SLList::getHead()
{
	return head;
}

void  SLList::setTail(SLLNode* inputTail)
{
	tail = inputTail;

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

SLLNode* SLList::getTail()
{
	return tail;
}

void SLList::importData()
{
	std::ifstream inputFile;

	inputFile.open(fileName, std::ios::binary);

	//To hold validation key
	char validationCode[17];

	//Reads first 17 Bytes for validation key
	inputFile.read(validationCode, 17);

	std::string validationString;

	validationString.assign(validationCode, 17);

	//Checks if validation key is present, if not logs an error and exits function
	if (validationString.compare("SLLFileForCarSpec") != 0)
	{
		std::cerr << "Invalid or Corrupted File\n";

		inputFile.close();

		return;
	}

	//This char array is specifically to read data for string data members
	char currentData[32];

	//CarSpec object will be contructed with the help of data stored in these variables
	std::string carCompanyName;
	std::string carModel;
	int carYear;
	int carColor;
	int carAvailabilityStatus;
	float carConditionScore;
	float carPriceUSD;
	float carRentUSD;
	float rentDiscountPercentage;
	float priceDiscountPercentage;
	bool isInsuredByCompany;

	//Will be used to insert nodes into list
	SLLNode* p;

	while (inputFile.read(currentData, 32)) //First string for each object is read here so loop breaks at EOF
	{
		//String assigned which is of length 32 for first data member
		carCompanyName.assign(currentData, 32);

		inputFile.read(currentData, 32);
		//and now for second data member
		carModel.assign(currentData, 32);

		//now depending on datatype, certain ammount of Byte(s) are read and stored in respective variables
		inputFile.read(reinterpret_cast<char*>(&carYear), 4);
		inputFile.read(reinterpret_cast<char*>(&carColor), 4);
		inputFile.read(reinterpret_cast<char*>(&carAvailabilityStatus), 4);
		inputFile.read(reinterpret_cast<char*>(&carConditionScore), 4);
		inputFile.read(reinterpret_cast<char*>(&carPriceUSD), 4);
		inputFile.read(reinterpret_cast<char*>(&carRentUSD), 4);
		inputFile.read(reinterpret_cast<char*>(&rentDiscountPercentage), 4);
		inputFile.read(reinterpret_cast<char*>(&priceDiscountPercentage), 4);
		inputFile.read(reinterpret_cast<char*>(&isInsuredByCompany), 1);

		//New node is created with CarSpec Object by the reading of the file above^
		p = new SLLNode(CarSpec(carCompanyName, carModel, carYear, (carColors)carColor,
			(availabilityStatus)carAvailabilityStatus, carConditionScore, carPriceUSD, carRentUSD,
			rentDiscountPercentage, priceDiscountPercentage, isInsuredByCompany));

		//To avoid nullptr exception, when tail is nullptr i.e list is empty, this process is skipped 
		if (length != 0)
		{
			tail->setNext(p);
		}

		//After last element's next is p, tail is set to p
		tail = p;

		//Length is incremented
		length++;

		//When there is one element in the list, the head is also set to first node
		if (length == 1)
		{
			head = tail;
		}
	}

	inputFile.close();
}

void SLList::exportData()
{
	std::ofstream outputFile;
	//File is in binary so mode is set to binary, and it clears file first
	outputFile.open(fileName, std::ios::binary | std::ios::trunc);

	//Hardcoded validation key to write to file
	std::string validationString = "SLLFileForCarSpec";

	//Writes validation key to first 17 Bytes
	outputFile << validationString;

	//To traverse list, p is initially set to head
	SLLNode* p = head;

	//These varaiables are filed with data member values to write a fixed number of Byte(s) in binary
	char carCompanyNameString[32];
	char carModelString[32];
	int intValue;
	float floatValue;
	bool boolValue;

	while (p != nullptr) //Traverses till after tail
	{
		//CarSpec object is aquired
		CarSpec data = p->getData();

		//17 Bytes is the Validation, then 32 + 32 + 4 * 8 + 1 Bytes i.e. 97 Bytes is the CarSpec ADT
		//Convert to binary:

		//String data member 1:
		strcpy_s(carCompanyNameString, data.getCarCompanyName().c_str());

		//If data member was less than 32 Bytes, the rest of the bytes are set to ' ', which is treated as a delimiter
		for (int i = data.getCarCompanyName().length(); i < 32; i++)
		{
			carCompanyNameString[i] = ' ';
		}

		//String data member written
		outputFile.write(carCompanyNameString, 32);

		//Repeat for String data member 2:
		strcpy_s(carModelString, data.getCarModel().c_str());

		for (int i = data.getCarModel().length(); i < 32; i++)
		{
			carModelString[i] = ' ';
		}

		outputFile.write(carModelString, 32);

		//intValue is set to next remaining int data member after each write 
		intValue = data.getCarYear();
		//Write int value in binary taking up 4 Byte(s)
		outputFile.write(reinterpret_cast<char*>(&intValue), 4);
		intValue = (int)data.getCarColor();
		outputFile.write(reinterpret_cast<char*>(&intValue), 4);
		intValue = (int)data.getCarAvailabilityStatus();
		outputFile.write(reinterpret_cast<char*>(&intValue), 4);
		//Now with float data members
		floatValue = data.getCarConditionScore();
		outputFile.write(reinterpret_cast<char*>(&floatValue), 4);
		floatValue = data.getCarPriceUSD();
		outputFile.write(reinterpret_cast<char*>(&floatValue), 4);
		floatValue = data.getCarRentUSD();
		outputFile.write(reinterpret_cast<char*>(&floatValue), 4);
		floatValue = data.getRentDiscountPercentage();
		outputFile.write(reinterpret_cast<char*>(&floatValue), 4);
		floatValue = data.getPriceDiscountPercentage();
		outputFile.write(reinterpret_cast<char*>(&floatValue), 4);
		//Now with bool data member
		boolValue = data.getIsInsuredByCompany();
		outputFile.write(reinterpret_cast<char*>(&boolValue), 1);

		//Traverse further
		p = p->getNext();
	}
}

void SLList::insertBeg(CarSpec inputData)
{
	//p has data and points to head
	SLLNode* p = new SLLNode(inputData, head);

	//Head is set to new first node which is p
	head = p;

	//Length is incremented
	length++;

	//When there is one element in the list, the head is also set to first node
	if (length == 1)
	{
		tail = head;
	}

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::insertBeforePOS(int POS, CarSpec inputData)
{
	//If POS is out of range
	if (POS >= length || POS < 0)
	{
		std::cerr << "Error: Position not valid\n";

		return;
	}

	//If insert before first element
	if (POS == 0)
	{
		insertBeg(inputData);

		return;
	}

	//Finds previous node to set it's next to new node
	SLLNode* previousNode = findNodePOS(POS - 1);

	//p has data and points to the previous nodes next
	SLLNode* p = new SLLNode(inputData, previousNode->getNext());

	//previous node's next is set to p
	previousNode->setNext(p);

	//Length is incremented
	length++;

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::insertBeforeDATA(CarSpec searchData, CarSpec inputData)
{
	SLLNode* p = head->getNext();
	SLLNode* q = head;

	while (p != nullptr && !(p->getData() == searchData))
	{
		q = p;

		p = p->getNext();
	}

	if (p->getData() == searchData)
	{
		insertAfterNODE(q, inputData);

		return;
	}

	std::cerr << "Data not present in List. Position not found\n";

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::insertAfterNODE(SLLNode* inputNode, CarSpec inputData)
{
	if (inputNode == tail)
	{
		insertEnd(inputData);

		return;
	}

	SLLNode* p = new SLLNode(inputData, inputNode->getNext());

	inputNode->setNext(p);

	length++;

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::insertAfterPOS(int POS, CarSpec inputData)
{
	//If POS is out of range
	if (POS >= length || POS < 0)
	{
		std::cerr << "Error: Position not valid\n";

		return;
	}

	if (POS == length - 1)
	{
		insertEnd(inputData);

		return;
	}

	SLLNode* currentNode = findNodePOS(POS);

	SLLNode* p = new SLLNode(inputData, currentNode->getNext());

	currentNode->setNext(p);

	length++;

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::insertAfterDATA(CarSpec searchData, CarSpec inputData)
{
	insertAfterNODE(findNodeDATA(searchData), inputData);
}

void SLList::insertEnd(CarSpec inputData)
{
	SLLNode* p = new SLLNode(inputData, nullptr);

	if (length != 0)
	{
		tail->setNext(p);
	}

	tail = p;

	length++;

	if (length == 1)
	{
		head = tail;
	}

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

int SLList::findPosNODE(SLLNode* inputNode)
{
	SLLNode* p = head;

	int POS = 0;

	while (p->getNext() != nullptr && p != inputNode)
	{
		p = p->getNext();
	}

	return POS;
}

SLLNode* SLList::findNodePOS(int POS)
{
	//If POS is out of range
	if (POS >= length || POS < 0)
	{
		std::cerr << "Error: Position not valid\n";

		return nullptr;
	}

	SLLNode* p = head;

	for (int i = 0; i < POS; i++)
	{
		p = p->getNext();
	}

	return p;
}

SLLNode* SLList::findNodeDATA(CarSpec searchData)
{
	SLLNode* p = head;

	while (p->getNext() != nullptr && !(p->getData() == searchData))
	{
		p = p->getNext();
	}

	if (p->getData() == searchData)
	{
		return p;
	}

	std::cerr << "Data not present in List. Position not found\n";

	return nullptr;
}

int SLList::findPOS(CarSpec searchData)
{
	SLLNode* p = head;

	int POS = 0;

	while (p->getNext() != nullptr && !(p->getData() == searchData))
	{
		POS++;

		p = p->getNext();
	}

	if (p->getData() == searchData)
	{
		return POS;
	}

	std::cerr << "Data not present in List. Position not found\n";

	return -1;
}

void SLList::replaceNodeNODE(SLLNode* inputNode, CarSpec replacementData)
{
	inputNode->setData(replacementData);

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::replaceNodePOS(int POS, CarSpec replacementData)
{
	SLLNode* p = findNodePOS(POS);

	p->setData(replacementData);

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::replaceNodeDATA(CarSpec searchData, CarSpec replacementData)
{
	SLLNode* p = findNodeDATA(searchData);

	p->setData(replacementData);

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::swapNodesDataNODEs(SLLNode* firstNode, SLLNode* secondNode)
{
	CarSpec tempData = firstNode->getData();

	firstNode->setData(secondNode->getData());

	secondNode->setData(tempData);

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::swapNodesDataPOSs(int firstPOS, int secondPOS)
{
	SLLNode* firstNode = findNodePOS(firstPOS);
	SLLNode* secondNode = findNodePOS(secondPOS);

	swapNodesDataNODEs(firstNode, secondNode);

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::swapNodesDataDATAs(CarSpec firstSearchData, CarSpec secondSearchData)
{
	SLLNode* firstNode = findNodeDATA(firstSearchData);
	SLLNode* secondNode = findNodeDATA(secondSearchData);

	swapNodesDataNODEs(firstNode, secondNode);

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::deleteNodePOS(int POS)
{
	//If POS is out of range
	if (POS >= length || POS < 0)
	{
		std::cerr << "Error: Position not valid\n";

		return;
	}

	if (POS == 0)
	{
		SLLNode* currentNode = head;
		head = currentNode->getNext();

		delete currentNode;

		length--;

		return;
	}

	SLLNode* previousNode = findNodePOS(POS - 1);
	SLLNode* currentNode = previousNode->getNext();
	previousNode->setNext(currentNode->getNext());

	delete currentNode;

	if (POS == length - 1)
	{
		tail = previousNode;
	}

	length--;

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::deleteNodeDATA(CarSpec searchData)
{
	int POS = findPOS(searchData);

	if (POS == -1)
	{
		return;
	}

	deleteNodePOS(POS);

	//Export changes to file
	if (!fileName.empty())
	{
		exportData();
	}
}

void SLList::deleteFile()
{
	remove(fileName.c_str());
}

void SLList::emptyListWithoutChangesToFile()
{
	if (length == 0)
	{
		return;
	}
	else if (length == 1)
	{
		delete head;
	}
	else
	{
		SLLNode* p = head->getNext();
		SLLNode* q = head;

		while (q->getNext() != nullptr)
		{
			delete q;

			q = p;
			p = p->getNext();
		}

		delete q;
	}

	length = 0;
	head = nullptr;
	tail = nullptr;
}

void SLList::displayAllADT()
{
	SLLNode* p = head;

	int counter = 0;

	while (p != nullptr)
	{
		std::cout << "Data at Position " << counter << ":\n";
		p->getData().display();
		std::cout << "\n";

		counter++;
		p = p->getNext();
	}
}

SLList::~SLList()
{
	emptyListWithoutChangesToFile();
}