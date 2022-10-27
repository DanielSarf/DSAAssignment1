#pragma once

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

#include "SLLNode.h"


class SLList
{
private:
	SLLNode* head;
	SLLNode* tail;
	std::string fileName; //Name of the file that should have the all CarSpec objects
	int length; //Length of the list. When empty it is 0, when it has 10 elements is 10 etc.

public:
	//Parameterized constructor takes fileName and imports data from it amd if it is not present, makes one
	SLList(std::string inputFileName);

	SLList();

	SLList& operator=(SLList& other);
	
	//Setter getter functions:
	void setHead(SLLNode* inputHead);
	SLLNode* getHead();
	void setTail(SLLNode* inputTail);
	SLLNode* getTail();
	
	//Checks if file is valid, then one by one constructs objects and inserts them into the list's end
	void importData();
	
	//Writes to file (in binary) the validation key and each CarSpec object based on position
	void exportData();
	
	//Returns true if list is empty
	bool isEmpty();
	
	//Returns the current lenght of the list
	int getLength();
	
	//Naming convention: NODE, POS and DATA capitalized at the end of each function tell by which criteria it is going to search location to insert, find, replace, swap, delete etc.
	//Inserts at the beginning of the list
	void insertBeg(CarSpec inputData);
	//Inserts before a node at a certain postion
	void insertBeforePOS(int POS, CarSpec inputData);
	//Searches by data (stops after first find), then inserts before it
	void insertBeforeDATA(CarSpec searchData, CarSpec inputData);
	//Inserts after a certain node
	void insertAfterNODE(SLLNode* inputNode, CarSpec inputData);
	//Inserts after a node at a certain postion
	void insertAfterPOS(int POS, CarSpec inputData);
	//Searches by data (stops after first find), then inserts after it
	void insertAfterDATA(CarSpec searchData, CarSpec inputData);
	//Inserts at the end of the list
	void insertEnd(CarSpec inputData);
	
	//Finds position the node is at
	int findPosNODE(SLLNode* inputNode);
	//Finds node at a certain position
	SLLNode* findNodePOS(int POS);
	//Searches for the node by data (stops after first find)
	SLLNode* findNodeDATA(CarSpec searchData);
	//Searches by data (stops after first find), to find the postion of the node
	int findPOS(CarSpec searchData);
	
	//Replaces data of a certain node
	void replaceNodeNODE(SLLNode* inputNode, CarSpec replacementData);
	//Replaces data of node at a certain position
	void replaceNodePOS(int POS, CarSpec replacementData);
	//Searches by data (stops after first find), to find node node to replace data with
	void replaceNodeDATA(CarSpec searchData, CarSpec replacementData);

	//Swaps data of two nodes
	void swapNodesDataNODEs(SLLNode* firstNode, SLLNode* secondNode);
	//Swaps data of two nodes at two certain positions
	void swapNodesDataPOSs(int firstPOS, int secondPOS);
	//Searches by data (stops after first find), to find both nodes to swap their data
	void swapNodesDataDATAs(CarSpec firstSearchData, CarSpec secondSearchData);
	
	//Deletes node at a certain postion
	void deleteNodePOS(int POS);
	//Searches by data (stops after first find), to delete the node it found
	void deleteNodeDATA(CarSpec searchData);

	void deleteFile();

	//Empties list by deleting each node, sets head and tail to nullptr and sets length to 0
	void emptyList();
	
	//Calls emptyList and then exports empty list to file
	void emptyListAndFile();
	
	//Traverses list to display
	void displayAllADT();
	
	//Calls emptyList
	~SLList();
};