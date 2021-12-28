#ifndef ASSGN2DYNAMICQUEUE_H
#define ASSGN2DYNAMICQUEUE_H
#include<iostream>

using namespace std;

// Queue node template
template <class T>
class QueueNode{
	
	public :
		T value;	// value in a node
		QueueNode<T> *next;	// pointer to the next node
		
		// constructor for creating a new node in queue
		QueueNode(T nodeValue){
			value = nodeValue;
			next = NULL;
		}
};


// Dynamic template
template <class T>
class DynamicQueue{
	
	private :
		QueueNode<T> *front;	// the front of the queue
		QueueNode<T> *rear;		// the rear of the queue
		int numItems;	// number of items in the queue
		
	public :
		DynamicQueue();		// constructor
		~DynamicQueue();	// destructor
		
		// Queue operations
		void enqueue(T);	// insert into queue
		void dequeue(T &);	// remove from queue
		bool isEmpty() const;
		bool isFull() const;
		void clear();
};


// the constructor creates an empty queue
template <class T>
DynamicQueue<T> :: DynamicQueue()
{
	front = NULL;
	rear = NULL;
	numItems = 0;
}


// destructor
template <class T>
DynamicQueue<T> :: ~DynamicQueue()
{
	clear();
}


// function enqueue inserts the value item at the rear of the queue
template <class T>
void DynamicQueue<T> :: enqueue(T item)
{
	QueueNode<T> *newNode = NULL;
	
	// create a new node and store the new value there
	newNode = new QueueNode<T>(item);
	
	// adjust front and rear as necessaray
	if (isEmpty()){	// if the linked list is empty 
		
		front = newNode;
		rear = newNode;
	}
	
	else{ // insert at the back !!!
		
		rear->next = newNode;
		rear = newNode;
	}
	
	numItems++;		// update numItems
}


// function dequeue removes the value at the front of the queue,
// and copies it into item
template <class T>
void DynamicQueue<T> :: dequeue(T &item)
{
	QueueNode<T> *temp = NULL;
	
	if(isEmpty()){
		
		cout << "The queue is empty.\n";
	}
	
	else{
		
		// save the front node value in item
		item = front->value;
		// remove the front node and delete it
		temp = front;
		front = front->next;
		delete temp;
		// update numItems
		numItems--;
	}
}


// function isEmpty returns true if the queue is empty, else false
template <class T>
bool DynamicQueue<T> :: isEmpty() const
{
	bool status;
	
	if (numItems > 0)
		status = false;
	else
		status = true;
	
	return status;
}


// function clear dequeues all the elements in the queue
template <class T>
void DynamicQueue<T> :: clear()
{
	T value;	// dummy variable for dequeue
	
	while(!isEmpty())
		dequeue(value);
}

#endif
