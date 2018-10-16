// Wesley Ryder
// Lab 9 
// 10/24/17
// Description to make a double linked list and learn more on how to make a copy constructor with 
// doubly linked lists.


/**********************************************************************
    This is the header file for a class that holds a doubly linked list
    of integers. Above the declaration of that class you will find a 
    declaration of a node class that is used in the construction of that
    list.
    The student will be asked to complete some incomplete parts of this 
    list class. 
	John Dolan 	School of EECS Ohio University Athens Ohio
			Fall 2017
**********************************************************************/

#include<iostream>

class node{
    public:
	node(int d = 0, node* p = NULL, node* n = NULL){
	    datafield = d; previousptr=p; nextptr = n;
	    }
	int data() {return datafield;}
	node *previous() {return previousptr;}
	node *next()  {return nextptr;}
	void set_data(int d){datafield = d;}
	void set_previous(node * p){previousptr = p;}
	void set_next(node *n) {nextptr = n;}
    private:
	int datafield;
	node *nextptr;
	node *previousptr;
};

class LList{
    public:
	LList(){
	    head = tail = NULL;
	    nodecount = 0;
	}
	void add_item(int item);
	void frontview()const;
	void rearview() const;
	~LList();
	int size()const {return nodecount;}
	LList(const LList& other);
    private:
	node* head;
	node* tail;
	int nodecount;
};
