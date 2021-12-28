#ifndef ASSGN2STACK_H
#define ASSGN2STACK_H
#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
class stackNode{
	
	public :
		T value;		// node value
		stackNode<T> *next;	// pointer to the next node
		
		// constructor
		stackNode (T nodeValue){
			value = nodeValue;
			next = nullptr;
		}
		
};

template <class T>
class stack{
	
	private :
		stackNode<T> *stackTop;		
		int count;
		
	public :
		T Top();	// return top value of the stack
		void Pop();	// delete the top of the stack
		void Push(T);	// add new data to the stack
		bool IsEmptyStack();
	 	bool IsFullStack();
		void destroyStack();	// delete all nodes in the stack
		void swapname(string);
		void display();		// display all elements of the stack
		void permutations(const char*);
		stack();
		~stack();
};

template<class T>
stack<T> :: stack(){
	
	stackTop = nullptr;
	count = 0;
}


template<class T>
stack<T> :: ~stack(){
	destroyStack();
}

template<class T>
T stack<T> :: Top(){
	
	if(!IsEmptyStack())
		return stackTop->value;
} 

template<class T>
void stack<T> :: Pop(){
	
	stackNode<T> *nodePtr;
	
	if(IsEmptyStack())
		cout << " Stack is Empty...\n";
	else{
		nodePtr = stackTop;
		stackTop = stackTop->next;
		delete nodePtr;
		count--;
	}
}


template<class T>
void stack<T> :: Push(T newValue){
	
	stackNode<T> *newNode;
	newNode = new stackNode<T>(newValue);
	if (stackTop = nullptr)	// if (IsEmptyStack())
		stackTop = newNode;
	else{
		newNode->next = stackTop;
		stackTop = newNode;
		count++;
	}
}

template<class T>
bool stack<T> :: IsEmptyStack(){
	
	if(stackTop == nullptr)
		return true;
	else
		return false;
}

template<class T>
void stack<T> :: destroyStack(){
	
	stackNode<T> *nodePtr;
	while (!IsEmptyStack()){	// while (stackTop!=NULL
		nodePtr = stackTop;
		stackTop = stackTop->next;
		delete nodePtr;
	}
}

template <class T>
void stack<T> :: display()
{
	stackNode<T> *newNode;
	
	// check for the stack underflow
	if (stackTop == NULL){
		
		cout << "\nStack Underflow";
		exit(1);
	}
	else{
		newNode = stackTop;
		
		while (newNode != NULL){
			// print node data
			cout << newNode->value << " ";
			
			// assign newNode link to newNode
			newNode = newNode->next;
		}
	}
}


template <class T>
void stack<T> :: swapname(string s)
{
	int n = s.length();
	// Weight index control array initialized by 0
	int p[n];
	for (int i = 0; i < n; i++)
	{
		// p[i] == i controls iteration and index boundaries for i
		p[i] = 0;
	}
	// i, j represents upper and lower bound index respectively for swapping
	int i = 1, j = 0;
	// Print given string, as only its permutations will be printed later
	Push(s);
	
	while (i < n)
	{
		if (p[i] < i)
		{
			// if i is odd then j = p[i], otherwise j = 0
			j = (i % 2) * p[i];
			
			swap(s[j], s[i]);
			// Pushcurrent permutation
			Push(s);
		
			p[i]++; // increase index "weight" for i by one
			i = 1;  // reset index i to 1
		}
		// otherwise p[i] == i
		else
		{
			// reset p[i] to zero
			p[i] = 0;
			// set new index value for i (increase by one)
			i++;
		}
	}
}

template <class T>
void stack<T> :: permutations(const char *word) 
{
    string s = word;
    sort(s.begin(), s.end());
    cout << s << endl;
    while(next_permutation(s.begin(), s.end()))
        cout << s << endl;
}

#endif
