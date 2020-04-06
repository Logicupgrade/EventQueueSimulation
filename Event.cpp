	
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

	void Event::helpedAt(int timeHelped)
	{
		this->helped = timeHelped;
		haveHelpedAt = true;
	}

	void Event::departedAt(int timeDeparted)
	{
		if( (timeDeparted >= 0) && (helped >= arrive) )
		{
			this->depart = timeDeparted;
			haveDepart = true;
		}
	}

	bool Event::calcValues()
	{

		bool claculatedValues = false;
		if(haveHelpedAt && haveDepart)
		{

			wait = helped-arrive;
			totalBankTime = arrive-depart;

			claculatedValues = true;

			cout<<"helped: "<<helped<<endl;
			cout<<"arrive: "<<arrive<<endl;
		}

		return claculatedValues;
	}

	int Event::getArrive()
	{
		return arrive;
	}

	int Event::getHelpedAt()
	{
		return helped;
	}

	int Event::getTransactionTime()
	{
		return transactionTime;
	}

	int Event::getDepart()
	{
		 return depart;
	}

	int Event::getWait()
	{
		return wait;
	}

	int Event::getTotalBankTime()
	{
		return totalBankTime;
	}
