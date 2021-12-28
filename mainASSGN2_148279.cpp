#include "ASSGN2LINKEDLIST.h"
#include "ASSGN2DYNAMICQUEUE.h"
#include "ASSGN2STACK.h"
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;


void menu()
{
	system("cls");
	// Display welcome screen
	cout << "\n\t\t____________________________________________________________\t\t\n";
	cout << "\t\t************************************************************\n";
	cout << "\t\t************************************************************";
	cout << endl;
	cout << "\t\t\tWELCOME TO ANAGRAM GENERATOR\t\t\t";
	cout << endl;	
	cout << "\t\t____________________________________________________________\t\t\n";
	cout << "\t\t************************************************************\n";
	cout << "\t\t************************************************************";
	cout << endl << endl;
			
	// Display the menu and get the user's choice	
	cout << "\n\tMENU\t\n";
	cout << endl;
	cout << " [1] |\tDisplay Anagram\n";
	cout << " [2] |\tAppend a word\n";
	cout << " [3] |\tDelete a word\n";
	cout << " [4] |\tInsert a word\n";
	cout << " [5] |\tDisplay all words\n";
	cout << " [6] |\tQuit\n";
	cout << " Please enter your choice: ";
	
	cout << endl << endl;
}


int main()
{
	LinkedList<string> list;	// list as object type class linked list - as string
	stack<string> list2;
	
	string word;
	int choice, pick;
	int max = 20;			
	
	// read file	
	ifstream anagramFile;
	anagramFile.open("anagram.txt");
	
	while(!anagramFile.eof())	// read data from text file
	{
		if(anagramFile.eof() == true)
			break;
		
		else{
			anagramFile >> word;
			list.appendNode(word);	
		}
	}
	anagramFile.close();	// close the file

	// push all elements of stack
	list2.Push("listen");
	list2.Push("bored");
	list2.Push("increase");
	list2.Push("beautiful");
	list2.Push("friend");
	list2.Push("flower");
	list2.Push("bread");
	list2.Push("television");

    
	do{
		menu();
		cin >> choice;
		switch(choice) {
			case 1 : // display anagram 
				cout << " Choose one word\n";
				cout << "\t 1. Listen\n";
				cout << "\t 2. Bored\n";
				cout << "\t 3. State\n";
				cout << "\t 4. Increase\n";
				cout << "\t 5. Friend\n";
				cout << "\t 6. Flower\n";
				cout << "\t 7. Bread\n";
				cin >> pick;
			
				if(pick == 1)
					list2.permutations("listen");	
				
				else if(pick == 2)
					list2.permutations("bored");
				
				else if(pick == 3)
					list2.permutations("state");
				
				else if(pick == 4)
					list2.permutations("increase");
				
				else if(pick == 5)
					list2.permutations("friend");
				
				else if(pick == 6)
					list2.permutations("flower");
				
				else if(pick == 7)
					list2.permutations("bread");
				
				else{
					break;
					cout << " The word does not exist in the file.\n";
				}

			case 2 : // append a new word
				cout << "\t\n Append a word : ";
				cin >> word;
				list.appendNode(word);
				break;
			
			case 3 : // delete
				cout << "\t\n Delete a word : ";
				cin >> word;
				list.deleteNode(word);
				break;
			
			case 4 : // insert a new word
				cout << "\t\n Insert a word : ";
				cin >> word;
				list.insertNode(word);
				break;
			
			case 5 : // display
				cout << "\t\n Display the list : ";
				list.displayList();		// display the content of linked list
				system("pause");
				break;
			
			case 6 : break;
			default : cout << " Wrong choice \n";
		}
	} while (choice!=6);
	
	cout << "-----------------------------";
	cout << "\n End of Program";
	
	return 0;
}
