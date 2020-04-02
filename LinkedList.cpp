
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

//returns pointer to node at position or nullptr if bad position
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position)
{
	bool positionExists = true;
	Node<ItemType>* currentPtr = headPtr;
	int i = 0;

	if( (position > nodeCount) || (position < 0) )
	{
		positionExists = false;
		currentPtr = nullptr;
	}

	while( (i < position) && positionExists)
	{
		currentPtr = currentPtr->getNext();
		i++;
	}

	return currentPtr;
}

//Adds to front of linked list
template<class ItemType>
bool LinkedList<ItemType>::insert(int position, const ItemType& newItem)
{
	bool ableToInsert = ( ( position <= (nodeCount+1) ) && (position >= 1) );

	Node<ItemType>* tempNodePtr = new Node<ItemType>(newItem);

	if( ableToInsert )
	{
		//adding first node 
		if( (position == 1) && (nodeCount < 1) )
	 	{
	 		tempNodePtr->setNext(nullptr);
	 		headPtr = tempNodePtr;
	 		tailPtr = tempNodePtr;
	 	}

		//adding to front 
		else if( (position == 1) && (nodeCount > 0) )
	 	{
	 		tempNodePtr->setNext(headPtr);
	 		headPtr = tempNodePtr;
	 	}

		//adding to end
		else if( (position == (nodeCount+1) ) && (nodeCount > 0) )
	 	{
			//setting up new node at end
	 		tempNodePtr->setNext(nullptr);
	 		tailPtr = tempNodePtr;

			//gets last node and points it to new Node
			getNodeAt(nodeCount)->setNext(tempNodePtr);

			tailPtr = tempNodePtr;
	 	}

		//adding to middle
		else if( (1 < position) && (position <= count) &&  (nodeCount > 1) )
	 	{
			Node<ItemType>* beforePtr;
			Node<ItemType>* afterPtr;
			
	 		tempNodePtr->setNext(nullptr);
	 		headPtr = tempNodePtr;
	 		tailPtr = tempNodePtr;

			beforePtr = getNodeAt(position - 1);
			afterPtr = getNodeAt(position + 1);

			beforePtr->setNext(tempNodePtr);
			tempNodePtr->setNext(afterPtr);			 
	 	} 

	 	nodeCount++;
	}
	
	return ableToInsert;
}

//Removes from front of linked list
template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
	bool ableToRemove = ( ( position <= nodeCount ) && (position >= 1) && (nodeCount > 0) );
	Node<ItemType>* tempNodePtr;
	
	if(ableToRemove)
	{
		//remove only node
		if( nodeCount == 1 && position == 1 )
		{
			delete headPtr;

			headPtr = nullptr;
			tailPtr = nullptr;
		}

		//remove front
		else if( nodeCount > 1 && position == 1 )
		{
			tempNodePtr = headPtr;

			headPtr = headPtr->getNext();

			delete tempNodePtr;
		}

		//remove middle
		else if( (nodeCount > 1) && (position < nodeCount) )
		{
			Node<ItemType>* tempNodePtr2;

			tempNodePtr = getNodeAt(position);
			tempNodePtr2 = getNodeAt(position-1);

			tempNodePtr2->setNext(tempNodePtr->getNext());

			delete tempNodePtr;

		}

		//remove end
		else if( nodeCount == position )
		{
			tempNodePtr = getNodeAt(position-1);

			delete tailPtr;

			tailPtr = tempNodePtr;
			tailPtr->setNext(nullptr);
		}

		nodeCount--;
	}

	return ableToRemove;
	
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