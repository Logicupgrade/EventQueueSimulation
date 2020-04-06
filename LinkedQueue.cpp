

#include "LinkedQueue.h"
// #include "LinkedList.cpp"

#include <iostream>
using namespace std;


template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue( const ItemType& newItem )
{
	//inserts node at the end of the list
	if(this->isEmpty())
	{
		this->insert(1, newItem);
	}
	else
	{
		this->insert( (this->getCount()) +1, newItem);
	}
	
	return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool didDQ = false;

	if(!this->isEmpty())
	{
		this->remove(1);
		didDQ = true;
	}

	return didDQ;
}

// template<class ItemType>
// bool LinkedQueue<ItemType>::isEmpty()
// {
// 	return listQ->isEmpty();
// }

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront()
{
	//dont call peekFront when listQ->isEmpty();
	return this->getEntry(1);
}

// template<class ItemType>
// int LinkedQueue<ItemType>::getCount()
// {
// 	return listQ->getCount();
// }