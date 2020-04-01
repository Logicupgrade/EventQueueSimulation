
#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Node.h"
#include <vector>

using namespace std;

template<class ItemType>
class LinkedList
{
private:
	int nodeCount;

	Node<ItemType>* headPtr;
	Node<ItemType>* tailPtr;

	Node<ItemType>* getNodeAt();

public:
	//constructor
	LinkedList();

	//destructor
	virtual ~LinkedList();

	//checks to see if list is empty
	bool isEmpty() const;

	//inserts new node at specified position
	bool insert(int position, const ItemType& newItem);

	//removes node at specified position
	bool remove(int position);

	//returns node count
	int getCount() const;

	//gets node item at specified position
	ItemType getEntry(int postion) const;

	//sets node item at specified position
	void setEntry(int postion, const ItemType& newItem) const;

	//creates vector of linked list
	vector<ItemType> toVector() const; 

};

#endif