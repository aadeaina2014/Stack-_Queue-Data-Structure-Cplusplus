/* Florida Institute Of Technology
   College of Engineering
   Electrical and Computer Engineering Department
   ECE 2552: Software Hardware Integration
   (c)February 2016, Ayokunle Ade-Aina, All rights rserved
*/

#include "LinkedQueue.h"
#include <iostream>

/*

Application of Linkedqueues : EMail processing, Network packet processing, Sales order processing,  Text Messaging, Registeration processing
                              System Task Scheduling, 
*/
using namespace std;



int main()
{

	LinkedQueue myLinkedQueue;
	cout << "***********************************************************************************" << endl;
	cout << "\t\t\tLinked Queue Test\n\t\t\tApplication Driver" << endl;
	cout << "***********************************************************************************\n\n" << endl;
	
	  ///////////////////////////
	 //   Initial State       //
	///////////////////////////
	cout << "checking initial state of Linked Queue..." << endl; 
	if (myLinkedQueue.empty())
	{
		cout << "\nQueue is empty" << endl;
		cout << "size of queue is" << myLinkedQueue.size() <<"\n"<< endl;
	}
	else
	{
		cout << "\nQueue is  not empty\n" << endl;
		cout << "size of queue is" << myLinkedQueue.size() << "\n" << endl;
	}

	  ///////////////////////////
	 //   Populating Queue    //
	///////////////////////////
	cout << "populating Linked Queue..." << endl;

	myLinkedQueue.enqueue("Ayo");
	myLinkedQueue.enqueue("kunle");
	myLinkedQueue.enqueue("Ade");
	myLinkedQueue.enqueue("Aina");

	cout << "queue contains " << myLinkedQueue.size() << " Items\n" << endl;

	  ///////////////////////////
	 //   Queue Processing    //
	///////////////////////////

	cout << "\nretieving  and processing items in Linked Queue..." << endl;
	while (!myLinkedQueue.empty())
	{
		cout << myLinkedQueue.front() << endl;
		myLinkedQueue.dequeue();
	}

	  ///////////////////////////
	 //   Final   State       //
	///////////////////////////
	cout << "\nchecking Final state of Linked Queue..." << endl;
	if (myLinkedQueue.empty())
	{
		cout << "Queue is empty" << endl;
		cout << "size of queue is" << myLinkedQueue.size() << "\n" << endl;
	}
	else
	{
		cout << "\nQueue is  not empty\n" << endl;
		cout << "size of queue is" << myLinkedQueue.size() << "\n" << endl;
	}
	cout << "\n\n***********************************************************************************" << endl;
	return EXIT_SUCCESS;
}