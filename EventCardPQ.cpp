#include "EventCardPQ.h"
#include "EventCard.h"

template<class ItemType>
EventCardPQ<ItemType>::EventCardPQ(bool ascend): PriorityQueue<EventCard>::PriorityQueue(ascend)
{
}

template<class ItemType>
EventCardPQ<ItemType>::~EventCardPQ()
{
}

template<class ItemType>
bool EventCardPQ<ItemType>::enqueue(const EventCard& newECard, int priorityVal)
{
	this->PriorityQueue<ItemType>::enqueue( newECard, priorityVal );

	return true;
}