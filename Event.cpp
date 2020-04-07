	
	#include <iostream>

	#include "Event.h"

	using namespace std;


	Event::Event(int arriveTime, int duration):arrive(arriveTime),transactionTime(duration)
	{
		if(duration<0)
		{
			cout<<"Can not have negative duration"<<endl;
			cout<<"Duration is now 0"<<endl;
			duration = 0;
		}
	}
	Event::~Event()
	{
	}

	int Event::getArrive()
	{
		return this->arrive;
	}

	int Event::getTransactionTime()
	{
		return this->transactionTime;
	}
