#include "SLLNode.h"

SLLNode::SLLNode(CarSpec inputData, SLLNode* inputNext)
{
	data = inputData;
	next = inputNext;
}

void SLLNode::setData(CarSpec inputData)
{
	data = inputData;
}

CarSpec SLLNode::getData()
{
	return data;
}

void SLLNode::setNext(SLLNode* inputNext)
{
	next = inputNext;
}

SLLNode* SLLNode::getNext()
{
	return next;
}