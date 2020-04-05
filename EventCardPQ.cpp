#include "EventCardPQ.h"

template<class ItemType>
EventCardPQ<ItemType>::EventCardPQ()
{
	eventCardPQ = new PriorityQueue<ItemType>();
}

template<class ItemType>
EventCardPQ<ItemType>::~EventCardPQ()
{
}

template<class ItemType>
bool EventCardPQ<ItemType>::enqueue(const EventCard& newECard, int priorityVal)
{
	eventCardPQ->enqueue( newECard, newECard.getETime() );	
}