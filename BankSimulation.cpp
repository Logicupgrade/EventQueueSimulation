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
int loadPQ(EventCardPQ<EventCard>* bankEventCards, LinkedQueue<Event>* bankEventLQ );

//3 display events(PQ)
void displayEvents( EventCardPQ<EventCard>* eCardSim );


int main()
{
	LinkedQueue<Event>* bankEvents = new LinkedQueue<Event>();
	EventCardPQ<EventCard>* eventRecord = new EventCardPQ<EventCard>(false);

	readEventsToLQ(bankEvents, "InputFile.txt");

	int averageWait = loadPQ( eventRecord, bankEvents );

	displayEvents(eventRecord);

	cout<<"count: "<<bankEvents->getCount()<<endl;

	cout<<"avg wait: "<<averageWait<<endl;

	//________Displays Bank Stats__________________
	// int i = 0;
	// int sum = 0;
	// int wait;

	// cout<<"count: "<<bankEvents->getCount()<<endl;

	// while( i<bankEvents->getCount() )
	// {
	// 	wait = bankEvents->getNodeAt(i)->getItem().getWait();
	// 	cout<<"wait: "<<wait<<endl;
	// 	sum += wait;
	// 	i++;
	// }

	// cout<<"avg wait: "<<(sum/10)<<endl;
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

int loadPQ(EventCardPQ<EventCard>* bankEventCards, LinkedQueue<Event>* bankEventLQ )
{
	int totalWaitTime = 0;
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

// void loadPQ(EventCardPQ<EventCard>* bankEventCards, LinkedQueue<Event>* bankEventLQ )
// {
// 	Node<Event>* currentNode;
	
// 	int timeKeeper = bankEventLQ->peekFront().getArrive();

// 	int currentPosition =1;
	
// 	while( currentPosition < bankEventLQ->getCount() +1 )
// 	{
// 		//Current Event = Current Node Data
// 		currentNode = bankEventLQ->getNodeAt(currentPosition);

// 		if( timeKeeper < currentNode->getItem().getArrive() )
// 		{
// 			timeKeeper = currentNode->getItem().getArrive();
// 		}
// 		cout<<"timeKeeper1: "<<timeKeeper<<endl;
// 		cout<<"currentPosition: "<<currentPosition<<endl;
// 		//customer was helped at this time
// 		currentNode->getItem().helpedAt(timeKeeper);

// 		cout<<"HelpedAtOutside: "<<currentNode->getItem().getHelpedAt()<<endl;

// 		//enqueue 'a',arrivalTime,duration
// 		EventCard tempCardA( 'a', currentNode->getItem().getArrive() , currentNode->getItem().getTransactionTime() );
// 		bankEventCards->enqueue( tempCardA,tempCardA.getETime() );

// 		//event driven time(departed) update
// 		timeKeeper += currentNode->getItem().getTransactionTime();

// 		//customer departed at this time
// 		currentNode->getItem().departedAt(timeKeeper);

// 		cout<<"DepartOutside: "<<currentNode->getItem().getDepart()<<endl;

		
// 		// cout<<"HelpedAtOutside: "<<currentNode->getItem().getHelpedAt()<<endl;
// 		// cout<<"DepartedAtOutside: "<< currentNode->getItem().getDepart()<<endl;
		

// 		//enqueue 'd',departure time,duration=0
// 		EventCard tempCardD('d', timeKeeper , 0);
// 		bankEventCards->enqueue( tempCardD, tempCardD.getETime() );

		
// 		//calculate wait time and total time at bank
// 		currentNode->getItem().calcValues(); 

// 		//increment node
// 		currentPosition++;
// 	}
// }

//3 display events(PQ)
void displayEvents( EventCardPQ<EventCard>* eCardSim )
{
	//reverse pQOrder want to keep priorityQ order as highest to lowest



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