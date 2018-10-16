//Wesley Ryder
// CS 2401 Lab 1 main.cc
// Aug 29 2017
// This is the main.cc for the lab1 project which the purpose of is to help us understand how not to use freind functions.

#include <iostream> // including librarys
#include <cstdlib>
#include <iomanip>
#include "MyTime.h" // including header file
using namespace std;

int main(){

	MyTime t1, t2;  // declaring objects
	int scalar;     // scalar int we use in program
	cout << "Enter time one: ";   // asking user to enter time one and time two
	cin >> t1;
	cout << "Enter time two: ";
	cin >> t2;
	cout << "Enter Scalar: ";
	cin >> scalar;
	
	cout << "Time One: " << t1 << " Time Two: " << t2 << endl;   // this uses the overloaded opperators that we created in the MyTime.cc file
	cout << "Scalar given: " << scalar << endl;					// Outputs the times info, like being added subtracted etc as well as a bool expression
	cout << "Times added: " << t1 + t2 << endl;
	cout << "Times substracted: " << t1 - t2 << endl;
	cout << "Time One multiplied by scalar: " << t1 * scalar << endl;
	cout << "Time Two multiplied by scalar: " << t2 * scalar << endl;
	cout << "Time One divided by scalar: " << t1 / scalar << endl;
	cout << "Time Two divided by scalar: " << t2 / scalar << endl;
	cout << "**EQUAL TO TEST**" << endl;
	if( t1 == t2){														// bool exppressions, showing what the relationships between times are
		cout << "Time One is equal to time Two!" << endl;				// as follows
	}
	else{
		cout << "Time One is not equal to time Two!" << endl;
	}
	cout << "**LESS THAN OR EQUAL TO TEST**" << endl;
	if (t1 <= t2){
		cout << "Time one is less than or equal to time two. " << endl;
	}
	else{
		cout << "Time one is greater than time two. " << endl;
	}
	cout << "**LESS THAN TEST**" << endl;
	if (t1 < t2){
		cout << "time one is less than time two. " << endl;

	}
	else{
		cout << "Time one is not less than time two. " << endl;
	}
 	return 0;
}

