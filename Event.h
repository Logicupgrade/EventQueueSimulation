
#ifndef _BANK_EVENT
#define _BANK_EVENT

class Event
{
private:
	int arrive = -1;//arriveTime
	int transactionTime = -1;//duration

public:
	Event(int arriveTime, int duration);
	~Event();
	int getArrive();
	int getTransactionTime();
};

#endif