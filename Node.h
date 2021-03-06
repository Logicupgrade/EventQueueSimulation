
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
	ItemType item;
	Node<ItemType>* next;
	int priorityValue;

public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	virtual ~Node();
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	void setPVal(int priority);
	ItemType getItem();
	Node<ItemType>* getNext()const;
	int getPVal()const;
};

#endif