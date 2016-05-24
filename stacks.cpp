
#include <iostream>
#include "ArrayStack.h"
#include "LinkedStack.h"



using namespace std;

int main(int argc, char ** argv)
{
	ArrayStack <int> myStack,myOtherStack;
	LinkedStack myLinkedStack, myOtherLinkedStack; //stack of string data, class is not templated
	cout << " \n\n\n*************Test Program for Linked Stack Data Structure***********\n\n\n" << endl;
	cout << "\n" << endl;

	cout << "\n\n*********************************" << endl;
	cout << "************Array Stack**********" << endl;
	cout << "*********************************" << endl;
	if (myStack.empty())
	{
		cout << "stack is empty " << endl;
	}
	else
	{
		cout << "current stack size is: " << myStack.size()<< endl;
	}
	
	  /////////////////////
	 //*Populate Stack *//
	/////////////////////

	myStack.push(6);
	myStack.push(4);
	myStack.push(6);
	myStack.push(6);
	myStack.push(4);
	myStack.push(3);
	myStack.push(8);
	myStack.push(0);
	myStack.push(5);
	myStack.push(9);

	  //////////////////////////////////
	 //* Retrieve Items from Stack * //
	//////////////////////////////////

	cout << "\nPrinting Arraystack content\n\n" << endl;
	while (!myStack.empty())
	{

		cout << myStack.top();
		myOtherStack.push(myStack.top());//stack to stack transfer
		myStack.pop();
	}
	
	cout << "\n" << endl;
	
	cout << "\nPrinting Arraystack2  content\n\n" << endl;
	while (!myOtherStack.empty())
	{

		cout << myOtherStack.top();
		myOtherStack.pop();
	}

	cout << "\n\n*********************************" << endl;
	cout << "***********Linked Stack**********" << endl;
	cout << "*********************************" << endl;
	
	cout << " \nnow populating linked stack...\n...\n" << endl;
	myLinkedStack.push("F");
	myLinkedStack.push("I");
	myLinkedStack.push("T");
	myLinkedStack.push("  ");
	myLinkedStack.push("P");
	myLinkedStack.push("A");
	myLinkedStack.push("N");
	myLinkedStack.push("T");
	myLinkedStack.push("H");
	myLinkedStack.push("E");
	myLinkedStack.push("R");
	myLinkedStack.push("S");
	cout << "\nPrinting linked stack content\n\n" << endl;
	while (!myLinkedStack.empty())
	{

		cout << myLinkedStack.top();
		myOtherLinkedStack.push(myLinkedStack.top());
		myLinkedStack.pop();
	}
	cout << "\n\nPrinting linked stack2 content\n\n" << endl;
	while (!myOtherLinkedStack.empty())
	{

		cout << myOtherLinkedStack.top();
		
		myOtherLinkedStack.pop();
	}
	cout << "\n\nSucessss!\n" << endl;
	return EXIT_SUCCESS;
}