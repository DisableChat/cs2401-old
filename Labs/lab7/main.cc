// Wesley Ryder
// 10/12/17
// LAB 7
// Description: to take numbers from a linked list and strip them of any duplicates 
// and to also take that fixed list and then make an new lesser and greater list depending 
// on the user input for the split value.

/*********************************************************************
     Lab Assignment 6: This is another lab assignment in working with 
     linked lists. We will be using a struct node, for its simplicity,
     and working with non-member functions here. The main point is to 
     work with the logic of a linked list. Do not be afraid to make 
     drawings on scrap paper.
     The prototypes for the functions that you are to implement are
     included. You should uncomment them when you are ready to write 
     the implementation.
           John Dolan				Spring 2014
*********************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node{
     int data;
     node * link;
};


// These are the three I have written for you
void build_list(node* & head);  // note that we are passing by reference
void show_list(const node* head);
int size(const node* head);

//These are the two that you are to write, as described in the 
//instructions page.
void remove_repeats(node*& head);
void split_list(const node* original, node*& lesser, node*& greater,int split_value);


int main(){
    int start, stop;
    int split;
    node* head = NULL;
    node *lesser;
    node * greater;

    start = time(NULL);
    build_list(head);
    stop = time(NULL);
    cout<<"Time to build list = "<<stop - start <<"seconds.\n";
    start = time(NULL);
    show_list(head);
    cout << endl;
    stop = time(NULL);
    cout<<"Time to print list = "<<stop - start<<"seconds.\n";
    cout<<"Size of the list = "<<size(head)<<endl;
    cout << endl;
    start = time(NULL);
    remove_repeats(head);
    stop = time(NULL);
	cout<<"Time to remove repeats = "<<stop - start<<"seconds.\n";
	start =time(NULL);
	show_list(head);
	cout << endl;
	cout<<"Time to print the fixed list = "<<stop - start<<"seconds.\n";
    cout<<"Size of the fixed list = "<<size(head)<<endl;
    cout << "Enter the Split Value less than or equal to 500: ";
	cin >> split;
	cout << endl;
	start = time(NULL);
    split_list(head, lesser, greater, split);
    stop = time(NULL);
    cout << endl;
    cout << "Time to build the two split lists: " <<stop - start<<"seconds.\n";

    cout<<"Size of the lesser list = "<<size(lesser)<<endl;
    cout<<"Size of the greater list = "<<size(greater)<<endl;


return 0;
}

// builds a linked list of 2000 random integers, all in the 1 to 500 range
void build_list(node*& head){
     node* cursor;
     head = new node;
     head->data = rand()%500 + 1;
     cursor = head;
     for(int i = 0; i < 2000; ++i){
	cursor->link = new node;
        cursor = cursor->link;
        cursor->data = rand()%500 + 1;
     }
     cursor->link = NULL;
}

// outputs the contents of a linked list to the screen
void show_list(const node* head){
      const node * cursor = head;
      while(cursor !=  NULL){
   	cout<<cursor->data<<"  ";
	cursor = cursor->link;
      }
     cout<<endl;
}

// returns the number of nodes in a linked list
int size(const node* head){
	const node* cursor = head;
	int count = 0;
	while(cursor != NULL){
  	    count++;
	    cursor = cursor->link;
	}
	return count;
}

// remove function that removes the  dublicates from the list that was generated.
void remove_repeats(node*& head){
	
	// declaring the nessisary pointers.
	node* bptr;
	node* cursor;
	node* tmp;

	//setting the pointer bptr to the head of the list. so bptr points to the head of linked list.
	bptr = head;
	// while the not at the end of the linked list.
	while(bptr != NULL){
		// setting a cursor to the bptr pointer so the cursor points to the same thing as bptr.
		cursor = bptr;
		// while what cursor is pointing to is not NULL do the follwoing 
		while(cursor -> link != NULL){
			// if what bptr and what the cursor is pointing to is the same data value then we remove it.
			if(bptr -> data == cursor -> link -> data){
				tmp = cursor -> link;
				// this makes the pointer point to the next node, skipping the one node we want to remove so we can delete that tmp later.
				cursor -> link = cursor -> link -> link;
				delete tmp;
			}
			// else cursor moves down list
			else{
				cursor = cursor -> link;
			}
		}
		// bptr moves down the list
		bptr = bptr -> link;
	}
}

// this is the split listfunciton it takes the splitvalue and makes two seperate lists for values less than the 
// split value and a list for the values greater than the split value.
void split_list(const node* original, node*& lesser, node*& greater,int split){
	node* cursor;
	node* cursor2;
	lesser = NULL;
	greater = NULL;

	// while the orignal list is not pointing at NULL
	while(original != NULL){

		// if the value is less than split target do the follwoing.
		if(original -> data < split){

			//case for when lesser link is pointing at null
			if(lesser == NULL){
				lesser = new node;
				lesser -> data = original -> data;
				lesser -> link = NULL;
			}
			// this adds the numbers in the linked list if theyre less than split value.
			else{
				cursor = lesser;
				while(cursor -> link != NULL){
					cursor = cursor -> link;
				}
				cursor -> link = new node;
				cursor = cursor -> link;
				cursor -> data = original -> data;
				cursor -> link = NULL;
			}
			original = original -> link;
		}
		// this is for if theyre greater than split so they can be added to the greater linked list.
		// same idea as the lesser list but now with the values greater than the split value.
		else if(original -> data > split){
			if(greater == NULL){
				greater = new node;
				greater -> data = original -> data;
				greater -> link = NULL;
			}
			else{
				cursor2 = greater;
				while(cursor2 -> link != NULL){
					cursor2 = cursor2 -> link;
				}
				cursor2 -> link = new node;
				cursor2 = cursor2 -> link;
				cursor2 -> data = original -> data;
				cursor2 -> link = NULL;
			}
			original = original -> link;
		}
		//else point at the next node.
		else{
			original = original -> link;
		}
	}

	// this is outputing the linked list of lesser
	cout << "All Numbers less than split value: " << endl;
	node* out;
	out = lesser;
	while(out != NULL){
		cout << out -> data << " ";
		out = out -> link;
	}

	// This is ouputing the linked list of greater
	cout << endl;
	cout << "All Numbers greater than split value: " << endl;
	node* out2;
	out2 = greater;
	while(out2 != NULL){
		cout << out2 -> data << " ";
		out2 = out2 -> link;
	}
	cout << endl;

}