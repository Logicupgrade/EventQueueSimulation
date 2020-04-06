
#include "EventCard.h"


EventCard::EventCard(char typeOfEvent, int startTime, int lengthOfEvent):eventType(typeOfEvent),
																			eventTime(startTime),
																				eventLength(lengthOfEvent)
{
}

EventCard::~EventCard()
{
}

char EventCard::getEType()const
{
	return eventType;
}

int EventCard::getETime()const
{
	return eventTime;
}

int EventCard::getELength()const
{
	return eventLength;
}
