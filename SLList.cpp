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

SLList& SLList::operator=(SLList& other)
{
	emptyListAndFile();
	
	SLLNode* p = other.getHead();

	for (int i = 0; i < other.getLength(); i++)
	{
		insertEnd(p->getData());

		p = p->getNext();
	}

	return *this;
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

	//Will be used to insert nodes into list
	SLLNode* p;
	CarSpec currentObject;

	while (inputFile.read(reinterpret_cast<char*>(&currentObject), 97)) //Each object is read here so loop breaks at EOF
	{
		//New node is created with CarSpec Object by the reading of the file above^
		p = new SLLNode(currentObject);

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
	CarSpec currentObject;

	while (p != nullptr) //Traverses till after tail
	{
		//17 Bytes is the Validation, then 32 + 32 + 4 * 8 + 1 Bytes i.e. 97 Bytes is the CarSpec ADT
		
		//Convert to binary:
		currentObject = p->getData();
		outputFile.write(reinterpret_cast<char*>(&currentObject), 97);

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

void SLList::emptyList()
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

void SLList::emptyListAndFile()
{
	emptyList();

	if (!fileName.empty())
	{
		std::cerr << "File not specified\n";

		exportData();
	}
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
	emptyList();
}