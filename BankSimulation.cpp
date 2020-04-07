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

//2 load events in PQ
double loadPQ(EventCardPQ<EventCard>* bankEventCards, LinkedQueue<Event>* bankEventLQ );

//3 display events(PQ)
void displayEvents( EventCardPQ<EventCard>* eCardSim );


int main()
{
	LinkedQueue<Event>* bankEvents = new LinkedQueue<Event>();
	EventCardPQ<EventCard>* eventRecord = new EventCardPQ<EventCard>(false);

	readEventsToLQ(bankEvents, "InputFile.txt");

	int customerCount = bankEvents->getCount();

	double averageWait = loadPQ( eventRecord, bankEvents );

	displayEvents(eventRecord);

	cout<<endl;
	cout<<"Final Statistics:"<<endl;
	cout<<"		 Total number of people processed: "<<customerCount<<endl;
	cout<<"		 Average amount of time spent waiting: "<<averageWait<<endl;

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

double loadPQ(EventCardPQ<EventCard>* bankEventCards, LinkedQueue<Event>* bankEventLQ )
{
	double totalWaitTime = 0;
	int arriveTime;
	int helpedTime;
	int customerCount = bankEventLQ->getCount();
	int timeKeeper = bankEventLQ->peekFront().getArrive();

	// Event* currentEvent = nullptr;
	
	while( !bankEventLQ->isEmpty() )
	{
		if( timeKeeper < bankEventLQ->peekFront().getArrive() )
		{
			timeKeeper = bankEventLQ->peekFront().getArrive();
		}
		
		//customer was helped at this time
		helpedTime = timeKeeper;
		arriveTime = bankEventLQ->peekFront().getArrive();
		totalWaitTime += helpedTime - arriveTime;

		//enqueue 'a',arrivalTime,duration
		EventCard tempCardA( 'a', bankEventLQ->peekFront().getArrive() , bankEventLQ->peekFront().getTransactionTime() );
		bankEventCards->enqueue( tempCardA,tempCardA.getETime() );

		//event driven time(departed) update
		timeKeeper += bankEventLQ->peekFront().getTransactionTime();
		
		//enqueue 'd',departure time,duration=0
		EventCard tempCardD('d', timeKeeper , 0);
		bankEventCards->enqueue( tempCardD, tempCardD.getETime() );

		bankEventLQ->dequeue();
	}

	return totalWaitTime/customerCount;
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