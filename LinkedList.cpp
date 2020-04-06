
#include "Node.cpp"
#include "LinkedList.h"

#include <iostream>

using namespace std;

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

	while( ((i+1) < position) && positionExists)
	{
		currentPtr = currentPtr->getNext();
		i++;
	}

	return currentPtr;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return(nodeCount == 0);
}

template<class ItemType>
bool LinkedList<ItemType>::clear()
{
	//deletes first node in loop until list is empty 
	while(!isEmpty())
	{
		remove(1);
	}

	return true;
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
		else if( (1 < position) && (position <= nodeCount) &&  (nodeCount > 1) )
	 	{
			Node<ItemType>* beforePtr;
			Node<ItemType>* afterPtr;

			beforePtr = getNodeAt(position - 1);
			afterPtr = getNodeAt(position);

			beforePtr->setNext(tempNodePtr);
			tempNodePtr->setNext(afterPtr);

			beforePtr = nullptr;
			afterPtr = nullptr;	 
	 	} 

	 	tempNodePtr = nullptr;
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
			tempNodePtr = this->getNodeAt(1);

			headPtr = this->getNodeAt(2);

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
ItemType LinkedList<ItemType>::getEntry(int position)
{

	Node<ItemType>* tempNodePtr;
	// ItemType tempItem; ****OOP Lesson: dont create temp objects(wont know params) 

	//one for the homies ;)
	if( (position < 1) || (position > nodeCount) )
	{
		cout<<"position out of bounds try again"<<endl;
		if(nodeCount<1)
		{
			cout<<"no Nodes fool"<<endl;
			exit(0);
		}
		else if( (position > nodeCount) )
		{
			cout<<"position > nodeCount"<<endl;
			cout<<"position: "<<position<<endl;
			cout<<"nodeCount: "<<nodeCount<<endl;
			exit(0);
		}
		else if (position < 1)
		{
			cout<<"why is position <1? Hack3r!"<<endl;
			exit(0);
		}
		else
		{
			cout<<"I was too tired to figure out why this happens haha"<<endl;
			exit(0);
		}
		
	}

	tempNodePtr = getNodeAt(position);

	return tempNodePtr->getItem();

}

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newItem)
{
	if( (position >= 1) && (position <= nodeCount) )
	{
		getNodeAt(position)->setItem(newItem);
	}
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

// template<class ItemType>
// ItemType LinkedList<ItemType>::getHead()const
// {
// 	return headPtr->getItem();
// }

// template<class ItemType>
// ItemType LinkedList<ItemType>::getTail()const
// {
// 	return tailPtr->getItem();
// }