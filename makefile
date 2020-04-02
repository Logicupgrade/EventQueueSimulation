CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) 

Test : TestLinkedList.o  LinkedList.o Node.o #InterfaceMenu.o
	$(CC) $(LFLAGS)  TestLinkedList.o  LinkedList.o Node.o -o Test #InterfaceMenu.o

TestLinkedList.o : TestLinkedList.cpp LinkedList.cpp Node.cpp #InterfaceMenu.cpp
	$(CC) $(CFLAGS)  TestLinkedList.cpp

LinkedList.o : LinkedList.cpp Node.cpp
	$(CC) $(CFLAGS)  LinkedList.cpp
	
Node.o : Node.cpp
	$(CC) $(CFLAGS)  Node.cpp

clean:
	\rm *.o Test
