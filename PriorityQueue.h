#ifndef _PRIORITY_QUEUE
#define _PRIORITY_QUEUE

#include "LinkedQueue.h"
// #include <vector>

template<class ItemType>
class PriorityQueue : public LinkedQueue<ItemType>
{
private:
	bool isAscending;
public:
	PriorityQueue(bool ascend);
	~PriorityQueue();
	bool enqueue(const ItemType& newItem, int pValue);
	void setAscending(bool ascend);
};

#endif