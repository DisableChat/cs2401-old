// Wesley Ryder
// CS2401
// Lab 2
// 9/5/17
// Description: to fix the given program in lab and to fix the b_sort function as well as other
// functions in the program so that the program sorts numbers correctly and then output them to 
// the file with "sorted" added.
//*******************************************
//    Implementation file for the Numlist class, which 
//    allows programmers to store a list of numbers that they
//    choose to have sorted if they like.
//	January 2013		John Dolan
//	Ohio University		EECS
//**********************************************/
#include "numlist.h"
using namespace std;

// Constructor
NumList::NumList(){
	used = 0;
}

void NumList::insert(int num){
	if(used <CAPACITY){
		data[used] = num;
		used++;
	}
	else{
		cout<<"Error. List capacity has been reached.\n";
	}
}

void NumList::load_from_file(istream& ins){
// The implementation of this function is left to the student

	ins >> data[used];		// inserting numbers from files and then using increments
	while (! ins.eof()){		// to go to next line of txt file.	
		used++;		
		ins >> data[used];
	}
}


void NumList::save_to_file(ostream& outs){
// The implementation of this function is left to the student
	for(size_t i = 0; i < used; i++){
		outs << data[i] << endl;	//outputing to text file the numbers
	}
}

void NumList::see_all()const{
	if(used == 0)
	    cout<<"Empty list.\n";
	else
	    for(size_t i = 0; i<used; ++i)
		cout<<data[i]<<endl;
}

int NumList::get_item(size_t index)const{
	if(index < used)
		return data[index];
	else
		return -1;
}
	
void NumList::b_sort(){
    bool done = false;
    int j;
    int tmp;
    while(!done){
	done = true;		// fixed the 3 errors causing the program to have logical
	for(j=used-1; j > 0; --j){  // errors in the program.
	    if(data[j] < data[j-1]){
		cout << "j is: " << j << endl;
		done = false;
		tmp = data[j];
		data[j] = data[j-1];
		data[j-1] = tmp;
	    }
	}
    }
}
