/********************************************************************* 
Wesley Ryder
9-21-17
Proj 2
Description: This is the test main to see if I can input two friends
and test the overloaded opperators.
*********************************************************************/


#include <iostream>
#include "friend.h"
using namespace std;


int main(){
	Friend f1, f2;

	cout << "Enter F1" << endl;
	cin >> f1;
	cout << "Enter F2" << endl;
	cin >> f2;

	cout << "info for f1: " << endl;
	cout << f1 << endl;
	cout << "info for f2: " << endl;
	cout << f2 << endl;

	if(f1 == f2){
		cout << "WOW THEYRE EQUAL MY DUDE!" << endl;
  	}
  	if(f1 != f2){
  		cout << "theyre not equal dude! " << endl;
  	}

	return 0;
}