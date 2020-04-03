
#include <iostream>

#include <string>

#include "LinkedQueue.cpp"

using namespace std;



int main()
{
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

	LinkedList<int>* LandL = leQ.peekFront();

	
	cout<<"front1: "<< LandL->getEntry(2) <<endl;//leQ.peekFront()
	// cout<<"count1: "<< leQ.getCount() <<endl;

	leQ.dequeue();
	leQ.dequeue();
	leQ.dequeue();

	// cout<<"front2: "<<leQ.peekFront()<<endl;
	// cout<<"count2: "<<leQ.getCount()<<endl;

	// cout<<"isEmpty1: "<<leQ.isEmpty()<<endl;

	leQ.dequeue();
	leQ.dequeue();
	
	// cout<<"front3: "<<leQ.peekFront()<<endl;
	// cout<<"count3: "<<leQ.getCount()<<endl;

	// cout<<"isEmpty2: "<<leQ.isEmpty()<<endl;

	leQ.dequeue();

	// cout<<"front4: "<<leQ.peekFront()<<endl;
	// cout<<"count4: "<<leQ.getCount()<<endl;

	// cout<<"isEmpty3: "<<leQ.isEmpty()<<endl;




	return 0;
}