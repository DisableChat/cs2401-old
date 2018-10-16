// Wesley Ryder
// cs2401 lab 3
// Setpember 12 2017
// Description: made a main to test memeory methods in c++ like static and auto.

#include <iostream>
using namespace std;


void pretty(); // making a main

int main(){

	for (int k = 0; k < 6; k++){ // making a for loop to see what the stars print out
		pretty();
	}

return 0;
}

void pretty(){			// defining the pretty function with different variable types.
	auto int x = 0;
	x++;
	for(int i = 0; i < x; ++i){ cout << '*';}
	cout << endl;
}
