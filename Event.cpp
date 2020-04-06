	
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
		helped = timeHelped;
		haveHelped = true;
	}

	void Event::departedAt(int timeDeparted)
	{
		if( (timeDeparted >= 0) && (helped >= arrive) )
		{
			// cout<<"Departed Inside1: "<<timeDeparted<<endl;
			depart = timeDeparted;
			haveDepart = true;
		}
	}

	bool Event::calcValues()
	{
		// cout<<"Helpedbool Inside: "<<haveHelpedAt<<endl;
		// cout<<"Departbool Inside: "<<haveDepart<<endl;
		bool claculatedValues = false;
		if(haveHelped && haveDepart)
		{
			// cout<<"HelpedAt Inside: "<<helped<<endl;
			// cout<<"Arrived Inside: "<<arrive<<endl;
			// cout<<"Departed Inside2: "<<depart<<endl;

			wait = helped-arrive;
			totalBankTime = arrive-depart;

			claculatedValues = true;

			
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
