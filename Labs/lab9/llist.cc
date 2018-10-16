// Wesley Ryder
// Lab 9 
// 10/24/17
// Description to make a double linked list and learn more on how to make a copy constructor with 
// doubly linked lists.

/************************************************************************
     This is the implementation file for the LList class which is a 
container based on a doubly linked list. The student is required to 
write the rearview function as well as the copy constructor. Note that 
the copy constructor will not be able to use the add function to produce 
a true copy because of the strange behavior of the add function, which 
treats all numbers divisible by five differently than other numbers.
************************************************************************/
#include<iostream>
#include "llist.h"
using namespace std;

void LList::frontview()const{
    node* cursor = head;
    while (cursor != NULL){
	cout<<cursor->data() <<"  ";
	cursor = cursor->next();
    }
}

// The student is required to write the implementation of this function
void LList::rearview()const{
	node* cursor = tail;
	while(cursor != NULL){
		cout << cursor -> data() << "  ";
		cursor = cursor ->previous();
	}

}


void LList::add_item(int item){
    if(head == NULL){
	head=tail=new node(item);
	nodecount++;
    }
    else if(item%5 == 0 && nodecount > 3){
	int i = 0;
	node* cursor=head;
	while(i < nodecount/2){
	    cursor = cursor->next();
	    i++;
	}

	//making a temp node with the data, the next of tmp points to cursor and then the previous of tmp points to the previous of the cursor.
	node* tmp = new node(item, cursor-> previous(), cursor);
	// the node  that is cursos previoius is now pointing at tmp.
	cursor -> previous() -> set_next(tmp);
	// the cursors's previous is now pointing at tmp.
	cursor -> set_previous(tmp);
	
	nodecount++;
    }
    else{
	tail->set_next(new node(item, tail));
	tail = tail->next();
	nodecount++;
    }
}

LList::~LList(){
   node* rmptr;
   while(head != NULL){
	rmptr=head;
	head = head->next();
	delete rmptr;
   }
}

//copy constructor
LList::LList(const LList& other){
	// if head = null case.
	if(other.head == NULL){head = NULL; tail = NULL;}
	else{
		node* sptr;
		node* dptr;
		node* tmp;
		// creating new head so we can start coppying from other.
		head = new node;
		head -> set_data(other.head -> data());
		dptr = head;
		sptr = other.head -> next();
		head -> set_previous(NULL);
		// while source potinter is not null keep adding more nodes so we keep coppying
		// the other to the copy we want to make. while also connecting all the nodes to the next
		// and previous correctly.
		while(sptr != NULL){
			tmp = dptr;
			dptr -> set_next(new node);
			dptr = dptr -> next();
			dptr -> set_data(sptr -> data());
			sptr = sptr -> next();
			dptr -> set_previous(tmp);
		}
		//tail points at destination pointer.
		tail = dptr;
		dptr -> set_next(NULL);
	}
}