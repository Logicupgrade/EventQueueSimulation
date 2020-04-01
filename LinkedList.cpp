
#include "Node.cpp"
#include "LinkedList.h"

template<class ItemType>
LinkedList<ItemType>::LinkedList():nodeCount(0), headPtr(nullptr), tailPtr(nullptr)
{
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt()
{
	
}

//Adds to front of linked list
template<class ItemType>
bool LinkedList<ItemType>::insert(int position, const ItemType& newItem)
{
	bool ableToInsert = ( ( position <= (nodeCount+1) ) && (position >= 1) );

	Node<ItemType>* tempNodePtr = new Node<ItemType>(newItem);

	if( ableToInsert )
	{
		if(nodeCount < 1)
	 	{
	 		tempNodePtr->setNext(nullptr);
	 		headPtr = tempNodePtr;
	 		tailPtr = tempNodePtr;
	 	}

	 	else
	 	{
	 		tempNodePtr->setNext(headPtr);
	 		headPtr = tempNodePtr;
	 	}
	
	 nodeCount++;
	}
	 

	 return true;
}

//Removes from front of linked list
template<class ItemType>
bool LinkedList<ItemType>::remove()
{
	Node<ItemType>* tempNodePtr = headPtr;
	
	if( nodeCount > 1 )
	{
		headPtr = headPtr->getNext();
		delete tempNodePtr;
		tempNodePtr = nullptr;
		nodeCount--;
	}
	
	//Only one node
	else if( nodeCount > 0)
	{
		delete tempNodePtr;
		tempNodePtr = nullptr;
		headPtr = nullptr;
		tailPtr = nullptr;
		nodeCount=0;
	}

	return true;
	
}

template<class ItemType>
int LinkedList<ItemType>::getCount() const
{
	return nodeCount;
}

template<class ItemType>
vector<ItemType> LinkedList<ItemType>::toVector() const
{
	vector<ItemType> tempVector;
	Node<ItemType>*	tempPtr = headPtr; 

	while(tempPtr != nullptr)
	{
		tempVector.push_back( tempPtr->getItem() );
		tempPtr = tempPtr->getNext();
	}
	
	return tempVector;
}