/*******************************************************************
Wesley Ryder
CS2401 Proj 1
Sep-11-2017
Description: This is the header file for the checkbook class. which
is an array that holds checks in it. The main.cc uses this in the 
menu so it can allow the user to write checks and manuplite their 
checkbook so they can keep track and sort it based on the menu 
options while also updating their balance.
********************************************************************/

#ifndef REKT //safeguard
#define REKT

#include <iostream>
#include <string>
#include "check.h"

class Checkbook{
	public:
		static const size_t SIZE = 200;
		Checkbook(std::string user){used = 0;};
		void load_from_file(std::istream& ifs); // inputs from file
		void deposit(double depamount); // input func
		void write_check(std::istream& cin); // input func
		double get_balance()const; 	//accessor function
		void show_all(std::ostream& outs)const; //output func
		void remove(int rmnum); //remove func
		void number_sort(); //sort func
		void date_sort(); // sort func
		double average()const;
		void payto_sort();
		void show(std::string payto_find)const;
		void save(std::ostream& ofs)const; //output func

	private:
		Check array[SIZE];
		std::size_t used;
		double balance;
};

#endif