

#include "PriorityQueue.h"

#include "LinkedQueue.h"
#include "LinkedList.h"

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
bool PriorityQueue<ItemType>::enqueue(const ItemType& newItem, int pValue)
{
	//point to first node if exists
	Node<ItemType>* tempPtr;
	int tempIndex = 1;
	bool hasInserted = false;

		
		while( ( tempIndex < (priorityQ->nodeCount+1) ) && !hasInserted )
		{
			//sets pointer to node of tempIndex 
			tempPtr =  priorityQ->getEntry(tempIndex);

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
				priorityQ->insert(tempIndex, newItem);

				//Sets priority Value of Node to pValue parameter
				priorityQ->getNodeAt(tempIndex)->setPValue(pValue);
				hasInserted = true;
				break;
			}
		}

		if( !hasInserted )
		{
			//enqueue(add to end);
			priorityQ->enqueue(newItem);

			//after having one node sets pVal
			priorityQ->peek()->setPValue(pValue);

			hasInserted = true;
		}

	return hasInserted;
}
