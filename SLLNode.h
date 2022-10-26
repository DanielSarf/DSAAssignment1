#pragma once

#include "CarSpec.h"

//Basic node for Singly linked list
class SLLNode
{
private:
	CarSpec data; //Node's data is an ADT
	SLLNode* next;

public:
	//Parameterized contructor sets next to a nullptr by default
	SLLNode(CarSpec inputData = CarSpec(), SLLNode* inputNext = nullptr);
	void setData(CarSpec inputData);
	CarSpec getData();
	void setNext(SLLNode* inputNext);
	SLLNode* getNext();
};