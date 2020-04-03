CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) 


Test : TestLinkedQueue.o  LinkedQueue.o LinkedList.o Node.o
	$(CC) $(LFLAGS)  TestLinkedQueue.o  LinkedList.o Node.o -o Test

TestLinkedQueue.o : TestLinkedQueue.cpp LinkedQueue.cpp LinkedList.cpp Node.cpp
	$(CC) $(CFLAGS)  TestLinkedQueue.cpp

# Test : TestLinkedList.o  LinkedList.o Node.o
# 	$(CC) $(LFLAGS)  TestLinkedList.o  LinkedList.o Node.o -o Test

# TestLinkedList.o : TestLinkedList.cpp LinkedList.cpp Node.cpp
# 	$(CC) $(CFLAGS)  TestLinkedList.cpp

LinkedQueue.o : LinkedQueue.cpp LinkedList.cpp Node.cpp
	$(CC) $(CFLAGS)  LinkedQueue.cpp

LinkedList.o : LinkedList.cpp Node.cpp
	$(CC) $(CFLAGS)  LinkedList.cpp
	
Node.o : Node.cpp
	$(CC) $(CFLAGS)  Node.cpp

clean:
	\rm *.o Test
