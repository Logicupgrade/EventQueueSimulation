
#ifndef _LINKED_QUEUE
#define _LINKED_QUEUE

#include "LinkedList.h"

teplate<class ItemType>
class LinkedQueue : private LinkedList<ItemType>
{
	public:
    LinkedQueue();
    ~LinkedQueue();
    bool enqueue();
    bool dequeue();
    bool isEmpty();
    ItemType peek();
}

#endif
