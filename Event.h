
#ifndef _BANK_EVENT
#define _BANK_EVENT

class Event
{
private:
	//values that will be placed
	int arrive = -1;//arriveTime
	int helped = -1;//timeHelped
	int transactionTime = -1;//duration
	int depart = -1;//timeDeparted

	//event and value dependent
	int wait = -1; //helpedAt-arrived
	int totalBankTime = -1;//arrive-depart

	bool haveHelpedAt = false;
	bool haveDepart = false;
public:
	Event(int arriveTime, int duration);
	~Event();
	void helpedAt(int timeHelped);//set HaveHelpedAt true
	void departAt(int timeDeparted);//set HaveDepart true
	bool calcValues();//check have bools

	int getArrive();
	int getHelpedAt();
	int getTransactionTime();
	int getDepart();
	int getWait();
	int getTotalBankTime();

};

#endif