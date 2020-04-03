
#include "EventCard.h"


EventCard::EventCard(char typeOfEvent, int startTime, int lengthOfEvent):eventType(typeOfEvent),
																			eventTime(startTime),
																				eventLength(lengthOfEvent)
{
}

EventCard::~EventCard()
{
}

char EventCard::getEType()
{
	return eventType;
}

int EventCard::getETime()
{
	return eventTime;
}

int EventCard::getELength()
{
	return eventLength;
}
