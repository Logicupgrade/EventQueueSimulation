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
bool EventCardPQ<ItemType>::enqueue(const EventCard& newECard)
{
	//Make this work in priorityQueue and remove priority from node
	//switch parameters in PQ to this
	eventCardPQ.enqueue( newECard, newECard.getETime() );
	
}