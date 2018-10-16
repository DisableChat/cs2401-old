// Wesley Ryder
// Lab 6
// 10/3/17
// Description: to work with pointers and help better our understanding on how they work.

#include <iostream>
#include <string>

struct Node{
	std::string data;
	Node *link;
};

class Lilist{
	public:
		Lilist(){head = NULL;}
		void add(std::string item);
		void show();
		Node* search(std:: string target);
		void move_front_to_back();
	private:
		Node *head;
};

void Lilist::add(std::string item){
	Node *tmp;
	if(head == NULL){
		head = new Node;
		head -> data = item;
		head -> link = NULL;
	}
	else{
		for(tmp = head; tmp -> link != NULL; tmp = tmp -> link);
		// this loop simply advances the pointer to the last node in the list
		
		tmp -> link = new Node;
		tmp = tmp -> link;
		tmp -> data = item;
		tmp -> link = NULL;
	}
}

// show function
void Lilist::show(){
	for(Node *tmp = head; tmp != NULL; tmp = tmp -> link)
		std::cout << tmp -> data << "  ";
}

// searches for target string
Node* Lilist::search(std:: string target){
	Node *cursor;
	cursor = head;
	while(cursor != NULL && cursor -> data != target){
		cursor = cursor -> link;			
	}
	return cursor;
}

// move front to back function 
void Lilist::move_front_to_back(){
	Node *cursor;
	Node *tmp;
	tmp = new Node; //making a temp node for head.
	
	cursor = head;
	//moving cursor down list to end of the list
	while(cursor -> link != NULL){
		cursor = cursor -> link; 
	}
	// setting cursor link to head
	cursor -> link = head;
	// setts the tmp link to head's link which is the second node
	tmp -> link = head -> link;
	// setting the previous link of head to NULL
	head -> link = NULL; 
	// sets the new head to what the tmps link is pointing at. so that head is updated
	head = tmp -> link; 
}





