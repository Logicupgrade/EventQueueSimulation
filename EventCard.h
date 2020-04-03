
class EventCard
{
private:
	char eventType = 'z';//a(arrive) or d(depart)
	int eventTime = -1;
	int eventLength = 0;
public:
	EventCard(char typeOfEvent, int startTime, int lengthOfEvent);
	~EventCard();
	char getEType();
	int getETime();
	int getELength();
};