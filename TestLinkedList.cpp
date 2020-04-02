

#include <iostream>

#include "LinkedList.cpp"

using namespace std;



int main()
{
	LinkedList<int> newList = LinkedList<int>(); 

	cout<<"isEmpty 1: "<<newList.isEmpty()<<endl;

	newList.insert(1,8);
	newList.insert(1,1);
	newList.insert(1,2);
	newList.insert(1,3);

	cout<<"isEmpty 2: "<<newList.isEmpty()<<endl;

	newList.clear();

	cout<<"isEmpty 3: "<<newList.isEmpty()<<endl;

	newList.insert(1,0);
	newList.insert(1,9);
	newList.insert(1,9);

	cout<<"getCount: "<<newList.getCount()<<endl;

	newList.remove(1);
	newList.remove(2);

	cout<<"getCount 2: "<<newList.getCount()<<endl;

	cout<<"isEmpty 4: "<<newList.isEmpty()<<endl;

	cout<<"getEntry: "<<newList.getEntry(1)<<endl;

	newList.setEntry(1,99);

	cout<<"getEntry 2: "<<newList.getEntry(1)<<endl;

	newList.insert(1,11);
	cout<<"debug1: "<<newList.getEntry(1)<<endl;
	cout<<"debug2: "<<newList.getEntry(2)<<endl;
	cout<<"debugh: "<<newList.getHead()<<endl;
	cout<<"debugt: "<<newList.getTail()<<endl;
	newList.insert(2,12);
	cout<<"debug1: "<<newList.getEntry(1)<<endl;
	cout<<"debug2: "<<newList.getEntry(2)<<endl;
	cout<<"debug3: "<<newList.getEntry(3)<<endl;
	cout<<"debugh: "<<newList.getHead()<<endl;
	cout<<"debugt: "<<newList.getTail()<<endl;
	newList.insert(2,13);
	
	newList.insert(5,100);

	newList.remove(1);
	newList.remove(3);
	newList.remove(3);
	newList.remove(2);
	newList.remove(1);
	newList.remove(1);
	


	vector<int> newV = newList.toVector();

	for (auto i = newV.begin(); i != newV.end(); ++i) 
        cout << *i << " ";

     cout<<endl;




	return 0;
}