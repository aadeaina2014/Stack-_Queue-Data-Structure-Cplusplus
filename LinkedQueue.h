#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUE_H_

#include "QueueException.h"



typedef std::string Elem;				// queue element type

class CNode {					// circularly linked list node
private:
	Elem elem;					// linked list element value
	CNode* next;				// next item in the list

	friend class CircleList;			// provide CircleList access
};

class CircleList {				// a circularly linked list
public:
	CircleList();				// constructor
	~CircleList();				// destructor
	bool empty() const;				// is list empty?
	const Elem& front() const;			// element at cursor
	const Elem& back() const;			// element following cursor
	void advance();				// advance cursor
	void add(const Elem& e);			// add after cursor
	void remove();				// remove node after cursor
private:
	CNode* cursor;				// the cursor 
};

CircleList::CircleList()			// constructor
	: cursor(NULL) { }
CircleList::~CircleList()			// destructor
{
	while (!empty()) remove();
}

void CircleList::add(const Elem& e) {		// add after cursor
	CNode* v = new CNode;			// create a new node
	v->elem = e;
	if (cursor == NULL) {			// list is empty?
		v->next = v;				// v points to itself
		cursor = v;				// cursor points to v
	}
	else {					// list is nonempty?
		v->next = cursor->next;			// link in v after cursor
		cursor->next = v;
	}
}

void CircleList::remove() {			// remove node after cursor
	CNode* old = cursor->next;			// the node being removed
	if (old == cursor) 				// removing the only node?
		cursor = NULL;				// list is now empty
	else
		cursor->next = old->next;			// link out the old node 
	delete old;					// delete the old node
}

bool CircleList::empty() const		// is list empty?
{
	return cursor == NULL;
}
const Elem& CircleList::back() const		// element at cursor
{
	return cursor->elem;
}
const Elem& CircleList::front() const		// element following cursor
{
	return cursor->next->elem;
}
void CircleList::advance()			// advance cursor
{
	cursor = cursor->next;
}
class LinkedQueue {				// queue as doubly linked list
public:
	LinkedQueue()				// constructor
	{
		n = 0;
	}
	int size() const				// number of items in the queue
	{
		return n;
	}
	bool empty() const				// is the queue empty?
	{
		return C.empty();
	}
	const Elem& front() const throw(QueueEmpty) // the front element
	{
		if (empty())
			throw QueueEmpty("trying to read an empty queue");
		return C.front();  //wrapper 
	}
	void enqueue(const Elem& e)		// enqueue element at rear
	{
		C.add(e);					// insert after cursor
		C.advance();				// ...and advance
		n++;
	}
	void dequeue() throw(QueueEmpty)		// dequeue element at front
	{
		if (empty())
			throw QueueEmpty("dequeue of empty queue");
		C.remove();					// remove from list front
		n--;
	}

private:					// member data
	CircleList C;				// circular list of elements
	int n;					// number of elements
};


/*
// enqueue element at rear
void LinkedQueue::enqueue(const Elem& e) {
C.add(e);					// insert after cursor
C.advance();				// ...and advance
n++;
}
// dequeue element at front
void LinkedQueue::dequeue() throw(QueueEmpty) {
if (empty())
throw QueueEmpty("dequeue of empty queue");
C.remove();					// remove from list front
n--;
}
*/




#endif