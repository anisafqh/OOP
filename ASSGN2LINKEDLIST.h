#ifndef ASSGN2LINKEDLIST_H
#define ASSGN2LINKEDLIST_H
#include<iostream>		// for cout and NULL
using namespace std;


// A class template for holding a linked list
template <class T>
class LinkedList{
	
	private:
		// Declare a structure for the list
		struct ListNode{
			T value;			// The value in this node
			struct ListNode *next;	// To point to the next node
		};
		ListNode *head;			// List head pointer
		
	public :
		// Constructor
		LinkedList(){ head = NULL; }
		
		// Destructor
		~LinkedList();
		
		// Linked list operations
		void appendNode(T);
		void insertNode(T);
		void deleteNode(T);
		void displayList() const;
		bool search(T);
};

//************************************************************************
// appendNode appends a node containing the value pased into newValue,
// to the end of the list
//*************************************************************************
template <class T>
void LinkedList<T> :: appendNode(T newValue)
{
	ListNode *newNode;		// To point to a new node
	ListNode *nodePtr;		// To move through the list
	
	// Allocate a new node and store newValue there
	newNode = new ListNode;
	newNode->value = newValue;
	newNode->next = NULL;
	
	// If there are no nodes in the list
	// make newNode the first node.
   if (!head)
      head = newNode;
   else{ // Otherwise, insert newNode at end.
   
      // Initialize nodePtr to head of list.
      nodePtr = head;

      // Find the last node in the list.
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // Insert newNode as the last node.
      nodePtr->next = newNode;
   } 
}

//********************************************************************
// the insertNode function inserts a node with
// newNode copied to its value member
//********************************************************************
template <class T>
void LinkedList<T> :: insertNode(T newValue)
{
	ListNode *newNode;		// A new node
	ListNode *nodePtr;		// to traverse the list
	ListNode *previousNode = NULL;	// the previous node
	
	// Allocate a new node and store newValue there
	newNode = new ListNode;
	newNode->value = newValue;
	newNode->next = NULL;
	
	// If there are no nodes in the list make 
	// newNode the first node
	if (!head){
		
		head = newNode;
		newNode->next = NULL; 
	}
	else{	// otherwise insert newNode
		nodePtr =  head;
		
		// Initialize previousNode to nullptr
		previousNode = NULL;
		
		// Skip all nodes whose value is less than newValue
		while (nodePtr != NULL && nodePtr->value < newValue){
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		// If the new node is to be the 1st in the list,
		// insert it before all other nodes
		if (previousNode == NULL){
			head = newNode;
			newNode->next = nodePtr;
		}
		else{	// otherwise insert after the previous node
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//***********************************************************************
// The deleteNode fuctiom searches for a node with
// searchValue as its value. The node, if found,
// is deleted from the list and from memory
//***********************************************************************
template <class T>
void LinkedList<T> :: deleteNode(T searchValue)
{
	ListNode *nodePtr;		// to traverse the list
	ListNode *previousNode;	// to point to the previous node
	
	// if the list is empty, do nothing
	if (!head)
		cout << "List is empty.\n";
	
	// Determine if the first node is the one
	if (head->value == searchValue){
		nodePtr = head;
		head = head->next;
		delete nodePtr;
	}
	else{	
		// initialize nodePtr to head of list
		nodePtr = head;
		
		// skip all nodes whose value member is
		// not equal to num
		while (nodePtr != NULL && nodePtr->value != searchValue){
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		// if nodePtr is not at the end of the list,
		// link the previous node to the node after nodePtr,
		// then delete nodePtr
		if (nodePtr){	// nodePtr is pointing to a node
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
		else{
			cout << "Cannot delete the value " << searchValue << endl;
			system("pause");
		}
	}
}

//************************************************************************
// displayList shows the value stored in each node
// of the linked list pointed to by head
//************************************************************************
template <class T>
void LinkedList<T> :: displayList() const
{
	ListNode *nodePtr;	// to move through the list
	
	// position nodePtr at the head of the list
	nodePtr = head;
	
	// while nodePtr points to a node, traverse the list
	cout << "head->";
	while (nodePtr){
		
		// display the value in this node
		cout << nodePtr->value << "->";
		
		// move to the next node
		nodePtr = nodePtr->next;
	}
	
	cout << "null" << endl;
}

//*************************************************************************
// destructor
// this function deletes every node in the list
//*************************************************************************
template <class T>
LinkedList<T> :: ~LinkedList()
{
	ListNode *nodePtr;		// to traverse the list
	ListNode *nextNode;		// to point to the next node
	
	// position nodePtr is not at the end of the list
	nodePtr = head;
	
	// while nodePtr is not at the end of the list
	while (nodePtr != NULL){
		
		// save a pointer to the next node
		nextNode = nodePtr->next;
		
		// delete the current node
		delete nodePtr;
		
		// position nodePtr at the next node
		nodePtr = nextNode;	
	}
}

template <class T>
bool LinkedList<T> :: search(T searchValue)
{
	ListNode *current = head;	// initialize current
	while (current!= NULL){
		
		if (current->value == searchValue)
			return true;
		
		current = current->next;
	}
	return false;
}


#endif
