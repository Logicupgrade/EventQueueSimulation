#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "LinkedQueue.h"

template<class ItemType>
class PriorityQueue : public LinkedQueue<ItemType>
{
private:
	LinkedQueue<ItemType>* priorityQ;
public:
	PriorityQueue();
	~PriorityQueue();
	bool enqueue(const ItemType& newItem, const int priorityValue);
};