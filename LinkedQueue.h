
#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE

#include "LinkedList.h"

template<class ItemType>
class LinkedQueue : public LinkedList<ItemType>
{
private:
	LinkedList<ItemType>* listQ;
public:
    LinkedQueue();
    ~LinkedQueue();
    bool enqueue(const ItemType& newItem);
    bool dequeue();
    // bool isEmpty();
    ItemType peekFront();
    // int getCount();
};

#endif
