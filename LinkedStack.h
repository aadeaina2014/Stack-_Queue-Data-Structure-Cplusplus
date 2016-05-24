
/****************************************************************************
                 Florida Institute Of Technology
                 College of Engineering
                 Electrical and Computer Engineering Department
                 ECE 2552 : Software Hardware Integration
                         Linked Stack

*****************************************************************************/



  //////////////////////////////////
 //*Interface for Linked Queue * //
//////////////////////////////////
#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_

#include "StackExceptions.h"

template <typename E>
class SNode {					// singly linked list node
private:
	E elem;					// linked list element value
	SNode<E>* next;
	// next item in the list
	template<class U> friend class SLinkedList;		// provide SLinkedList access
};

template <typename E>
class SLinkedList {				// a singly linked list
public:
	SLinkedList();				// empty list constructor
	~SLinkedList();				// destructor
	bool empty() const;				// is list empty?
	const E& front() const;			// return front element
	void addFront(const E& e);			// add to front of list
	void removeFront();				// remove front item list
	void printList();

private:
	SNode<E>* head;				// head of the list
};

template <typename E>
SLinkedList<E>::SLinkedList()				// constructor
	: head(NULL) { }

template <typename E>
bool SLinkedList<E>::empty() const			// is list empty?
{
	return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const		// return front element
{
	return head->elem;
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {		// add to front of list
	SNode<E>* v = new SNode<E>;				// create new node
	v->elem = e;					// store data
	v->next = head;					// head now follows v
	head = v;						// v is now the head
}

template <typename E>
SLinkedList<E>::~SLinkedList()			// destructor
{
	while (!empty()) removeFront();
}

template <typename E>
void SLinkedList<E>::removeFront() {			// remove front item
	SNode<E>* old = head;				// save current head
	head = old->next;					// skip over old head
	delete old;						// delete the old head
}

template <typename E>
void SLinkedList<E>::printList()
{
	cout << "SLinkedList of Elements\n";
	while (!empty())
	{
		E val = head->elem;
		std::cout << val << std::endl;
		removeFront();
	}

}





typedef std::string Elem;				// stack element type
class LinkedStack {				// stack as a linked list
public:
	LinkedStack();				// constructor
	int size() const;				// number of items in the stack
	bool empty() const;				// is the stack empty?
	const Elem& top() const throw(StackEmpty);	// the top element
	void push(const Elem& e);  			// push element onto stack
	void pop() throw(StackEmpty);		// pop the stack
private:                                	// member data
	SLinkedList<Elem> S;			// linked list of elements
	int n;					// number of elements
};


LinkedStack::LinkedStack()
	: S(), n(0) { }				// constructor

int LinkedStack::size() const
{
	return n;
}				// number of items in the stack

bool LinkedStack::empty() const
{
	return n == 0;
}

// get the top element
const Elem& LinkedStack::top() const throw(StackEmpty) {
	if (empty()) throw StackEmpty("Top of empty stack");
	return S.front();
}
void LinkedStack::push(const Elem& e) {	// push element onto stack
	++n;
	S.addFront(e);
}
// pop the stack
void LinkedStack::pop() throw(StackEmpty) {
	if (empty()) throw StackEmpty("Pop from empty stack");
	--n;
	S.removeFront();
}

#endif