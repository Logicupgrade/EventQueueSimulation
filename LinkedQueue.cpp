

#include "LinkedQueue.h"
// #include "LinkedList.cpp"


template<class ItemType>
LinkedQueue<ItemType>::LinkedQueue()
{
	listQ = new LinkedList<ItemType>();
}

template<class ItemType>
LinkedQueue<ItemType>::~LinkedQueue()
{
	//hopefully invokes LinkedList destructor lol
}

template<class ItemType>
bool LinkedQueue<ItemType>::enqueue( const ItemType& newItem )
{
	//inserts node at the end of the list
	if(listQ->isEmpty())
	{
		listQ->insert(1, newItem);
	}
	else
	{
		listQ->insert( (listQ->getCount()) +1, newItem);
	}
	
	return true;
}

template<class ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
	bool didDQ = false;

	if(!listQ->isEmpty())
	{
		listQ->remove(1);
		didDQ = true;
	}

	return didDQ;
}

template<class ItemType>
bool LinkedQueue<ItemType>::isEmpty()
{
	return listQ->isEmpty();
}

template<class ItemType>
ItemType LinkedQueue<ItemType>::peekFront()
{
	//dont call peekFront when listQ->isEmpty();
	return listQ->getEntry(1);
}

template<class ItemType>
int LinkedQueue<ItemType>::getCount()
{
	return listQ->getCount();
}