

#include "Priority.h"

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
	priorityQ = new LinkedQueue<ItemType>();
}

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
}

template<class ItemType>
PriorityQueue<ItemType>::enqueue(const ItemType& newItem)
{

}