
#include <iostream>

#include "EventCardPQ.cpp"
#include "PriorityQueue.cpp"
#include "LinkedQueue.cpp"
#include "LinkedList.cpp"
#include "Event.cpp"
#include "EventCard.cpp"

using namespace std;



int main()
{
	PriorityQueue<int> intPQ;
	PriorityQueue<Event> eventPQ;
	PriorityQueue<EventCard> eCardPQ;

	
	// int one = 1;
	// int two = 2;
	// int three = 3;

	// intPQ.enqueue(one,1);
	// intPQ.enqueue(two,2);
	// intPQ.enqueue(three,20);

	// cout<<"count: "<<intPQ.getCount()<<endl;
	// cout<<"peek: "<<intPQ.getNodeAt(1)->getPVal()<<endl;

	// intPQ.dequeue();

	// cout<<"count: "<<intPQ.getCount()<<endl;
	// cout<<"peek: "<<intPQ.getNodeAt(1)->getPVal()<<endl;

	
	// Event party(1,5);
	// Event dinner(2,10);
	// Event Christmas(3,2);

	// eventPQ.enqueue(dinner,56);
	// eventPQ.enqueue(party,32);
	// eventPQ.enqueue(Christmas,100);

	// cout<<"count: "<<eventPQ.getCount()<<endl;
	// cout<<"peek: "<<eventPQ.getNodeAt(1)->getPVal()<<endl;
	// cout<<"arrive: "<<eventPQ.getNodeAt(1)->getItem().getArrive()<<endl;

	// eventPQ.dequeue();

	// cout<<"count: "<<eventPQ.getCount()<<endl;
	// cout<<"arrive: "<<eventPQ.getNodeAt(1)->getItem().getArrive()<<endl;


	// EventCard EOWorld('a', 1, 10);
	// EventCard Birthday('d', 9, 0);
	// EventCard performance('f', 5, 1);

	// eCardPQ.enqueue(EOWorld,4);
	// eCardPQ.enqueue(Birthday,31);
	// eCardPQ.enqueue(performance,-2);

	// cout<<"pval1: "<<eCardPQ.getNodeAt(1)->getPVal()<<endl;
	// cout<<"pval2: "<<eCardPQ.getNodeAt(2)->getPVal()<<endl;
	// cout<<"pval3: "<<eCardPQ.getNodeAt(3)->getPVal()<<endl;
	// cout<<"count: "<<eCardPQ.getCount()<<endl;

	// cout<<"pval1: "<<eCardPQ.getNodeAt(1)->getPVal()<<endl;
	// cout<<"type1: "<<eCardPQ.getNodeAt(1)->getItem().getEType()<<endl;
	// cout<<"length1: "<<eCardPQ.getNodeAt(1)->getItem().getELength()<<endl;
	// cout<<"time1: "<<eCardPQ.getNodeAt(1)->getItem().getETime()<<endl;

	// eCardPQ.dequeue();

	// cout<<"count: "<<eCardPQ.getCount()<<endl;
	// cout<<"type2: "<<eCardPQ.getNodeAt(1)->getItem().getEType()<<endl;
	// cout<<"length2: "<<eCardPQ.getNodeAt(1)->getItem().getELength()<<endl;
	// cout<<"time2: "<<eCardPQ.getNodeAt(1)->getItem().getETime()<<endl;

	// cout<<"front pval: "<<eCardPQ.getNodeAt(1)->getPVal()<<endl;

	EventCardPQ<EventCard> eventCardLineup;

	EventCard hotdog('a', 0, 5);
	EventCard colddog('b', 3, 5);
	EventCard warmdog('c', 4, 5);

	eventCardLineup.enqueue(hotdog,hotdog.getETime());
	eventCardLineup.enqueue(colddog,colddog.getETime());
	eventCardLineup.enqueue(warmdog,warmdog.getETime());

	cout<<"pval1: "<<eventCardLineup.getNodeAt(1)->getPVal()<<endl;
	cout<<"pval1: "<<eventCardLineup.getNodeAt(2)->getPVal()<<endl;
	cout<<"pval1: "<<eventCardLineup.getNodeAt(3)->getPVal()<<endl;


	cout<<"type1: "<<eventCardLineup.getNodeAt(1)->getItem().getEType()<<endl;
	cout<<"time1: "<<eventCardLineup.getNodeAt(1)->getItem().getETime()<<endl;
	cout<<"Length1: "<<eventCardLineup.getNodeAt(1)->getItem().getELength()<<endl;

	eventCardLineup.dequeue();
	eventCardLineup.dequeue();

	cout<<"type2: "<<eventCardLineup.getNodeAt(1)->getItem().getEType()<<endl;
	cout<<"time2: "<<eventCardLineup.getNodeAt(1)->getItem().getETime()<<endl;
	cout<<"Length2: "<<eventCardLineup.getNodeAt(1)->getItem().getELength()<<endl;

	eventCardLineup.dequeue();
	eventCardLineup.dequeue();





	return 1;
}