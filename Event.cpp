	
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

	void Event::helpedAt(const int& timeHelped )
	{
		
		this->helped = timeHelped;
		this->haveHelped = true;
	}

	void Event::departedAt(const int& timeDeparted)
	{
		if( timeDeparted >= 0 )
		{	
			this->depart = timeDeparted;
			this->haveDepart = true;
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

			this->wait = helped-arrive;
			totalBankTime = arrive-depart;

			claculatedValues = true;

			
		}

		return claculatedValues;
	}

	int Event::getArrive()
	{
		return this->arrive;
	}

	int Event::getHelpedAt()
	{
		return this->helped;
	}

	int Event::getTransactionTime()
	{
		return this->transactionTime;
	}

	int Event::getDepart()
	{
		 return this->depart;
	}

	int Event::getWait()
	{
		return this->wait;
	}

	int Event::getTotalBankTime()
	{
		return this->totalBankTime;
	}
