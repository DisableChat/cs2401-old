/******************************************************************
	Wesley Ryder
	9-21-17
	Proj 2
	Description: This is the class for friend, provided
	by proffesor Dolan. further information can be foud in the
	next text box.
******************************************************************/


/************************************************
   This is the header file for a class called Friend.
   It holds the information about a single Facebook
   friend, just their name and birthday. It uses a class
   called Date for the storage of the birthday. The member 
   functions are just accessors and input/output functions.
       John Dolan	Spring 2014	Ohio University
***********************************************************/

#include<iostream>
#include<string>
#include "date.h"
#ifndef FRIEND_H
#define FRIEND_H


class Friend{
    public:
	Friend(); //defualt constructor
	std::string get_name()const; // accesor functions
	Date get_bday()const;
	bool operator == (const Friend& other)const; // overloading constructors
	bool operator != (const Friend& other)const;
	void input(std::istream& ins);		// input and output functions
	void output(std::ostream& outs)const;
    private:
	std::string name;
	Date bday;
};

std::istream& operator >>(std::istream& ins,Friend& f);
std::ostream& operator <<(std::ostream& outs,const Friend& f);

#endif

