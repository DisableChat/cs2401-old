/*******************************************************************************
	Wesley Ryder
	CS2401 Proj 3
	10-10-17
	Description: This is the implementation file of the college class. More 
			information regarding this class can be found in the header file 
			for college.
*******************************************************************************/

#include <iostream>
#include "college.h"
#include <fstream>
using namespace std;

// defualt constructor
College::College(string n){
	name = n;
	head = NULL;
}

// copy contstructor part of big 3.
College::College(const College& other){
	// in the situation the list head = null which is empty.
	if(other.head == NULL){
		head = NULL;
	}
	// else the list is  not empty
	else{
		node* sptr;
		node* dptr;
		
		// head points to a new node and then we insert the data for that node
		// while also setting what our pointers are pointing at.
		head = new node(other.head -> data());
		dptr = head;
		sptr = other.head -> link();

		//this while loop allows us to go thorugh the list. and while not at null
		// create a new node that destination pointer points to and then filling that data in
		// and then making that newly  added node point to null. (adding onto the  linked list.)
		while(sptr != NULL){
			dptr -> set_link(new node);
			dptr = dptr -> link();
			dptr -> set_data(sptr -> data());
			sptr = sptr -> link();
		}
		dptr -> set_link(NULL);
	}
}

// deconstructor, part of big 3.
College::~College(){
	node* rptr;
	while(head != NULL){
		rptr = head;
		head = head -> link();
		delete rptr;
	}
}

// asssignment opperator, part of big 3.
College& College::operator = (const College& other){
	if(this == &other){
		return *this;
	}

	node *rptr;
	while(head != NULL){
		rptr = head;
		head = head -> link();
		delete rptr;
	}
	if(other.head != NULL){
		head = new node(other.head -> data());
		const node* sptr;
		node* dptr;
	}
	return *this;
} 

// load function allows us to  read to the end of file  and then take from the file 
// and input it into the data of those nodes. while connecting all the nodes.
void College::load(ifstream& fin){
	course tmp;
	node* cursor;

	tmp.input(fin);
	while( !fin.eof()){
		if(head == NULL){
			head = new node;
			head -> set_data(tmp);
			head -> set_link(NULL);
		}
		else{
			cursor = head;
			while(cursor -> link() != NULL){cursor = cursor -> link();}
			cursor -> set_link(new node);
			cursor = cursor -> link();
			cursor -> set_data(tmp);
			cursor -> set_link(NULL);
		}
		tmp.input(fin);
	}
}

// saves the manipulated courses list to the output file.
void College::save(ofstream& fout){
	for(node* cursor = head; cursor != NULL; cursor = cursor -> link()){
		fout << cursor -> data();
	}
}


// this is the insert function. this allows the user to insert courses into the list.
void College::add(const course& c){
	// declaring local variables.
 	node* cursor;
 	node* previous;
 	node* tmp;
 	tmp = new node;

 	// this is for the case if the file is completly empty and the user is entering a new course.
 	if(head == NULL){
 		head = new node;
 		head -> set_data(c);
 		head -> set_link(NULL);
 	}

 	// this is for the case if the course they enter is comes before the very first course listed
 	// so it then puts that course in front and making it the head while also connecting it to
 	// what was known as the previous head.
 	else if(c < head -> data()){
 		cursor = head;
 		head = new node;
 		head -> set_data(c);
 		head -> set_link(cursor);
 	}

 	// this is for the casses of inserting it somewhere in the list after the head or at the end of the list.
 	// both of which we just insert it and change the links to point at the correct nodes.
 	else{
 		// assigning the data passed through the parameters to tmps data.
 		tmp -> set_data(c);
 		cursor = head;

 		// walking through the list.
 		while(cursor != NULL && c > cursor -> data()){
 			previous = cursor;
 			cursor = cursor -> link();
 		}
 		// if cursor = null case.
 		if(cursor == NULL){
 			previous -> set_link(tmp);
 			tmp -> set_link(NULL);
 		}
 		// reassing what the links are pointing at.
 		// so its prooperly inserted.
 		else{
 			tmp -> set_link(cursor);
 			previous -> set_link(tmp);
 		}
 	}
}

// display function, just walks through the linked list and outputs the data to the screen.
void College::display(ostream& outs)const{
	node* tmp;
	tmp = head;
	
	while(tmp != NULL){
		outs << tmp -> data() << endl;
		tmp = tmp -> link();
	}
}

// remove function removes the user requested course. so if it finds the course
void College::remove(const string& n){
	node* cursor;
	node* previous;

	// if you try to remove from empty list case. so you dont get segfualt.
	if(head == NULL){
		cout << "Course was not found in college record!" << endl;
		return;
	}

	//head = target case.
	if(head -> data().get_course_number() == n){
		cursor = head;
		head = head -> link();
		delete cursor;
	}
	// else somewhere in the list then do the following which is to remove target by
	// assingng the previous cursor to point at the node after the removed one. 
	else{
		cursor = head;
		while(cursor != NULL && cursor -> data().get_course_number() != n){
			previous = cursor;
			cursor = cursor -> link();
		}
		if(cursor != NULL){
			previous -> set_link(cursor -> link());
			delete cursor;
		}
		else{
			cout << "Course was not found in college record!" << endl;
		}
	} 
}

// hours function just finds total hours of the courses youve taken.
double College::hours()const{
	double h = 0;
	node* cursor;
	cursor = head;

	//walking through the list and adding all the hours.
	while(cursor != NULL){
		h += cursor -> data().get_hours();
		cursor = cursor -> link();	
	}
	return h;
}


// cacluates the users gpa by going through the linked list.
double College::gpa()const{
	double total_hours = 0, h = 0, total_grade = 0, grade = 0;
	node* cursor;
	cursor = head;

	// while not at end of linked list find the total grade pints and total hours.
	while(cursor != NULL){
		h = cursor -> data().get_hours();
		grade = cursor -> data().get_number_grade();
		total_grade += grade * h;
		total_hours += cursor -> data().get_hours();
		cursor = cursor -> link();
	}
	//magic forumula
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	//returning the actual gpa value
	return (total_grade/total_hours);
}
		