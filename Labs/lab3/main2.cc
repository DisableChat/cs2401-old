// Wesley Ryder
// cs2401 lab 3
// Setpember 12 2017
// Description: made a main to test memeory methods and where points point to.

#include <iostream>
using namespace std;

int main(){
	
	int* ptr;	//declaring variables.
	ptr = new int;
	*ptr = 2401;
	for (int i = 0; i <110; i++){  // seeing where pointers point to the address
		++(*ptr);		// and couting what they show us.
	cout << *ptr << "Is stored at " << ptr << endl;

	}

	return 0;
}
