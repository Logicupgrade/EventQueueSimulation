
#include <iostream>

#include <string>

#include "PriorityQueue.cpp"
#include "LinkedQueue.cpp"
#include "LinkedList.cpp"
#include "Event.cpp"
#include "EventCard.cpp"

using namespace std;



int main()
{

	//**** Linked List and Queue testing *******************
	LinkedQueue<LinkedList<int>*> leQ;

	LinkedList<int> List1;
	LinkedList<int> List2;
	LinkedList<int> List3;
	LinkedList<int> List4;
	LinkedList<int> List5;

	LinkedList<int>* leList1 = &List1;
	LinkedList<int>* leList2 = &List2;
	LinkedList<int>* leList3 = &List3;
	LinkedList<int>* leList4 = &List4;
	LinkedList<int>* leList5 = &List5;


	leList1->insert(1,99);
	leList1->insert(1,101);

	leQ.enqueue(leList1);
	leQ.enqueue(leList2);
	leQ.enqueue(leList3);
	leQ.enqueue(leList4);
	leQ.enqueue(leList5);

	// LinkedList<int>* LandL = leQ.peekFront();

	
	cout<<"front1: "<< leQ.peekFront()->getEntry(2) <<endl;
	cout<<"count1: "<< leQ.getCount() <<endl;

	leQ.dequeue();
	leQ.dequeue();
	leQ.dequeue();

	cout<<"front2: "<<leQ.peekFront()<<endl;
	cout<<"count2: "<<leQ.getCount()<<endl;

	cout<<"isEmpty1: "<<leQ.isEmpty()<<endl;

	leQ.dequeue();
	leQ.dequeue();
	
	cout<<"count3: "<<leQ.getCount()<<endl;

	cout<<"isEmpty2: "<<leQ.isEmpty()<<endl;

	leQ.dequeue();

	// ***** Event and Queue testing objects and pointers ****************

	LinkedQueue<Event*> eQ;

	Event* event1 = new Event(3,4);

	eQ.enqueue(event1);
	

	cout<<"Arrive: "<<eQ.peekFront()->getArrive()<<endl;

	eQ.dequeue();


	LinkedQueue<Event> eObjectQ;

	Event eObject1(1,4);

	eObjectQ.enqueue(eObject1);

	cout<<"Arrive: "<<eObjectQ.peekFront().getArrive()<<endl;

	eObjectQ.dequeue();

	// ***** EventCard and Queue testing objects and pointers ****************
	LinkedQueue<EventCard*> eCardQ;

	EventCard* eventCard1 = new EventCard('a',3,4);

	eCardQ.enqueue(eventCard1);
	

	cout<<"ecard type: "<<eCardQ.peekFront()->getEType()<<endl;

	eCardQ.dequeue();


	LinkedQueue<EventCard> eCardObjectQ;

	EventCard eCardObject1('d',1,4);

	eCardObjectQ.enqueue(eCardObject1);

	cout<<"ecard type: "<<eCardObjectQ.peekFront().getEType()<<endl;

	eCardObjectQ.dequeue();

	// Coming Soon
	

	return 0;
}