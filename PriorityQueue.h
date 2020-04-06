#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "LinkedQueue.h"
// #include <vector>

template<class ItemType>
class PriorityQueue : public LinkedQueue<ItemType>
{
public:
	PriorityQueue();
	~PriorityQueue();
	bool enqueue(const ItemType& newItem, int pValue);
};

#endif