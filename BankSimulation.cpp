#include <iostream>
#include <fstream>
#include <string>

#include "EventCardPQ.cpp"
#include "PriorityQueue.cpp"
#include "LinkedQueue.cpp"
#include "LinkedList.cpp"
#include "Event.cpp"
#include "EventCard.cpp"

using namespace std;
 
//1 read in data into Event LinkedQ
void readEventsToLQ(LinkedQueue<Event>* bankEventLQPtr, string inputFile);

//2 initialize sim
// void initSim()

//2 load events in PQ
void loadPQ(EventCardPQ<EventCard>* bankEventCards, LinkedQueue<Event>* bankEventLQ );

//3 display events(PQ)
void displayEvents( EventCardPQ<EventCard>* eCardSim );


int main()
{
	LinkedQueue<Event>* bankEvents = new LinkedQueue<Event>();
	EventCardPQ<EventCard>* eventRecord = new EventCardPQ<EventCard>();

	readEventsToLQ(bankEvents, "InputFile.txt");

	loadPQ( eventRecord, bankEvents );

	displayEvents(eventRecord);

	//________displays bankEvents__________________
	// int i = 0;
	// int arrival;
	// int transactionTime;
	// cout<<"count: "<<bankEvents->getCount()<<endl;
	// while( i<bankEvents->getCount() )
	// {
	// 	arrival = bankEvents->getNodeAt(i)->getItem().getArrive();
	// 	transactionTime = bankEvents->getNodeAt(i)->getItem().getTransactionTime();

	// 	cout<<"arrive: "<<arrival<<"	duration: "<<transactionTime<<endl;
	// 	i++;
	// }
	//_____________________________________________
	

	return 1;
}

void readEventsToLQ(LinkedQueue<Event>* bankEventLQPtr, string inputFile)
{
	string line;
	int arriveTime;
	int duration;
	ifstream inFile;

	inFile.open(inputFile);

	while( !inFile.eof() )
	{		
		getline(inFile,line,'	');
		arriveTime = stoi(line);

		getline(inFile,line);
		duration = stoi(line);

		Event eventToAdd(arriveTime, duration);

		bankEventLQPtr->enqueue(eventToAdd);
	}

	inFile.close();

}

void loadPQ(EventCardPQ<EventCard>* bankEventCards, LinkedQueue<Event>* bankEventLQ )
{
	Event* currentEvent;
	
	int timeKeeper = bankEventLQ->peekFront().getArrive();

	int currentPosition =1;
	
	while( currentPosition < bankEventLQ->getCount() +1 )
	{
		//Current Event = Current Node Data
		*currentEvent = bankEventLQ->getNodeAt(currentPosition)->getItem();

		if( timeKeeper < currentEvent->getArrive() )
		{
			timeKeeper = currentEvent->getArrive();
		}

		//customer was helped at this time
		currentEvent->helpedAt(timeKeeper);

		//enqueue 'a',arrivalTime,duration
		EventCard tempCardA( 'a', currentEvent->getArrive() , currentEvent->getTransactionTime() );
		bankEventCards->enqueue( tempCardA,tempCardA.getETime() );

		//event driven time(departed) update
		timeKeeper += currentEvent->getTransactionTime();

		//customer departed at this time
		currentEvent->departedAt(timeKeeper);		

		//enqueue 'd',departure time,duration=0
		EventCard tempCardD('d', timeKeeper , 0);
		bankEventCards->enqueue( tempCardD, tempCardD.getETime() );

		//calculate wait time and total time at bank
		currentEvent->calcValues(); 

		//increment node
		currentPosition++;
	}
}

//3 display events(PQ)
void displayEvents( EventCardPQ<EventCard>* eCardSim )
{
	cout<<"Simulation Begins"<<endl;

	while( !eCardSim->isEmpty() )
	{
		if(eCardSim->peekFront().getEType() == 'a')
		{
			cout<<"Processing an arrival event at time:    "<<eCardSim->peekFront().getETime()<<endl;
		}
		else if (eCardSim->peekFront().getEType() == 'd')
		{
			cout<<"Processing a departure event at time:   "<<eCardSim->peekFront().getETime()<<endl;
		}

		eCardSim->dequeue();
	}

	cout<<"Simulation Ends"<<endl;
}