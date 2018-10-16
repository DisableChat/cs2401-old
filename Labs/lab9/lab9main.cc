// Wesley Ryder
// Lab 9 
// 10/24/17
// Description to make a double linked list and learn more on how to make a copy constructor with 
// doubly linked lists.


/******************************************************************
    This is the main for the Lab 9 Assignment of CS2401. You will need 
to implement the rearview function which should display the list 
backwards. Also, there are problems in the code which you will need to 
diagnose using gdb.
Finally you will also need to write and test the copy constructor for 
this class.
	John Dolan	School of EECS Ohio University, Athens Ohio
			Fall 2017
********************************************************************/

#include<iostream>
#include<cstdlib>
#include "llist.h"
using namespace std;

int main(){

    int n;
    LList somenums;
    for(int i = 0; i <35; ++i)
    {	n = rand()%700 + 1;
	somenums.add_item(n);
    }
// Once you have written the rear-view this should let you
// see the list frontwards and backwards.
      somenums.frontview();
      somenums.rearview();

// This part will be uncommented once you have written the copy constructor

{
    LList numcopy(somenums);  // call to the copy constructor
    numcopy.frontview();
    numcopy.rearview();

}   // Line 34 - What happens here?

// Checking the original list
   somenums.frontview();
   somenums.rearview();
return 0;
}
	

