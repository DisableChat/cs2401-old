// Wesley Ryder
// CS2401 LAB 1 MyTime.cc file
// Aug 29 2017
// The implementation file for the MyTime class
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
// Constructors

MyTime::MyTime(int h , int m){			// Defualt constructor
	hours = h;
	minutes = m;
}

void MyTime::Reset(int h, int m){		
	hours = h;
	minutes = m;
}

void MyTime::simplify(){  // simplifys time function
       	hours += minutes/60;
	minutes = minutes%60;
}

MyTime MyTime::operator + (const MyTime& t1)const{ //overloading the + opperator function so we can add objects times.
	MyTime tmp;
    tmp.hours = hours + t1.hours;
	tmp.minutes = minutes + t1.minutes;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator - (const MyTime& t1)const{		// overloading the - opperator function so we can subtract objects times
	MyTime tmp;
	tmp.minutes = abs((t1.hours*60+t1.minutes) - (hours*60+minutes));
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator / (int num)const{		// overlaoding the / opperator function so we can divide two objects.
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes /= num;
	tmp.simplify();
	return tmp;
}

MyTime MyTime::operator * (int num)const{ // overlaoding the * opperator so we can mutiply the times by a scalar
	MyTime tmp;
	tmp.minutes = hours*60 + minutes;
	tmp.minutes *= num;
	tmp.simplify();
	return tmp;
}

bool MyTime::operator == (const MyTime& t1)const{   // overlaoding the == so we can use bool expressions
	return t1.hours == hours && t1.minutes == minutes;
}

bool MyTime::operator < (const MyTime& t1)const{		 // overaloading the < ooperator
	return (hours*60 + minutes) < (t1.hours*60 + t1.minutes);
}

bool MyTime::operator <=(const MyTime& t1)const{		// overloading the <= opperator
	return (hours*60 + minutes) <= (t1.hours*60 + t1.minutes);
}

void MyTime::input(){
    // Here you are to copy the implementation code from the >> operator shown below
	// remember to that variables will be local here - so no referene to t1
    //Then you can have the >> operator call this function.
    // In the .h file remove the word friend for the operator and move its prototype to a spot
    // under the class declaration
	char junk;
	cin>>hours;			// this allows us to input hours and mins
  	cin.get(junk);
	cin>>minutes;
	simplify();
	
}

void MyTime::output()const{
	// Do the same thing a you did for the function above except using the code for the << 
	//operator
    cout<<hours<<':'<<setw(2)<<setfill('0')<<minutes;
	
}


ostream& operator <<(ostream& outs, const MyTime& t1){  
    t1.output();		// output operator function
	return outs;
}

istream& operator >> (istream& ins, MyTime& t1){
	t1.input();   //input opperator function
	return ins;
}

