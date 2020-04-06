

#include "PriorityQueue.h"

#include "LinkedQueue.h"
#include "LinkedList.h"

#include <iostream>

using namespace std;

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
}

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
}

template<class ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newItem, int pValue)
{
	//point to first node if exists
	Node<ItemType>* tempPtr;
	int tempIndex = 1;
	bool hasInserted = false;

		while( ( tempIndex < ( this->getCount()+1 ) ) && !hasInserted )
		{
			//sets pointer to node of tempIndex 
			tempPtr =  this->getNodeAt(tempIndex);

			//true: node p value greater than newItem p value
			if( tempPtr->getPVal() >= pValue )
			{

				//go to next node tempIndex++
				tempPtr = tempPtr->getNext();
				tempIndex++;

				
			}

			//sets Entry at index, breaks while, hasInserted = true
			else
			{
				//Inserts node with new Item
				this->insert(tempIndex, newItem);

				//Sets priority Value of Node to pValue parameter
				this->getNodeAt(tempIndex)->setPVal(pValue);
				hasInserted = true;
				
				break;

			}
		}


		if( !hasInserted )
		{
			//enqueue(add to end);
			this->insert(tempIndex,newItem);

			//after having one node sets pVal
			this->getNodeAt(tempIndex)->setPVal(pValue);

			hasInserted = true;
		}

	return hasInserted;
}
