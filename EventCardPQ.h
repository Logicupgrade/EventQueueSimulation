#ifndef _EVENTCARD_PRIORITY_QUEUE
#define _EVENTCARD_PRIORITY_QUEUE

#include "PriorityQueue.h"
#include "EventCard.h"

template<class ItemType>
class EventCardPQ : public PriorityQueue<ItemType>
{
private:
	PriorityQueue<ItemType>* eventCardPQ;
public:
	EventCardPQ(bool ascend);
	~EventCardPQ();
	bool enqueue(const EventCard& newECard, int priorityVal);
};

#endif