CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) 

# *******Testing PriorityQueue************************
Test : TestPriorityQueue.o EventCardPQ.o PriorityQueue.o LinkedQueue.o LinkedList.o Node.o Event.o EventCard.o
	$(CC) $(LFLAGS)  TestPriorityQueue.o -o Test

TestPriorityQueue.o : TestPriorityQueue.cpp EventCardPQ.cpp PriorityQueue.cpp LinkedQueue.cpp LinkedList.cpp Node.cpp Event.cpp EventCard.cpp
	$(CC) $(CFLAGS)  TestPriorityQueue.cpp

# *******Testing LinkedQueue************************
# Test : TestLinkedQueue.o LinkedQueue.o LinkedList.o Node.o Event.o
# 	$(CC) $(LFLAGS)  TestLinkedQueue.o -o Test

# TestLinkedQueue.o : TestLinkedQueue.cpp LinkedQueue.cpp LinkedList.cpp Node.cpp Event.cpp
# 	$(CC) $(CFLAGS)  TestLinkedQueue.cpp

# *******Testing LinkedList************************
# Test : TestLinkedList.o  LinkedList.o Node.o
# 	$(CC) $(LFLAGS)  TestLinkedList.o  LinkedList.o Node.o -o Test

# TestLinkedList.o : TestLinkedList.cpp LinkedList.cpp Node.cpp
# 	$(CC) $(CFLAGS)  TestLinkedList.cpp

EventCardPQ.o : EventCardPQ.cpp PriorityQueue.cpp LinkedQueue.cpp LinkedList.cpp Node.cpp EventCard.cpp
	$(CC) $(CFLAGS)  EventCardPQ.cpp

PriorityQueue.o : PriorityQueue.cpp LinkedQueue.cpp LinkedList.cpp Node.cpp
	$(CC) $(CFLAGS)  PriorityQueue.cpp

LinkedQueue.o : LinkedQueue.cpp LinkedList.cpp Node.cpp
	$(CC) $(CFLAGS)  LinkedQueue.cpp

LinkedList.o : LinkedList.cpp Node.cpp
	$(CC) $(CFLAGS)  LinkedList.cpp
	
Node.o : Node.cpp
	$(CC) $(CFLAGS)  Node.cpp

Event.o : Event.cpp
	$(CC) $(CFLAGS)  Event.cpp

EventCard.o : EventCard.cpp
	$(CC) $(CFLAGS)  EventCard.cpp

clean:
	\rm *.o Test
