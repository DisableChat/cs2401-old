/********************************************************************
Wesley Ryder
CS2401 Proj 1
Sep-11-2017
Description: this is the check.cc provided by Dolan. just updated
two functions "write_check" and "output" function.
********************************************************************/

/*******************************************************************
    This is the implementation file for the Check class. For more 
information about the class see check.h.
    Students are expected to implement some of the functions shown 
below.
	John Dolan	Ohio University		September 2017
******************************************************************/
#include "check.h"
using namespace std;

    Check::Check(Date d, string p, int num,double amt){
	checknum = num;
	date = d;
	payto = p;
	amount = amt;
	}
    // Input and output functions

	// defining the write check function so when you call this function it will
	// insert the the check info from istream.

    void Check::write_check(std::istream& ins){
    	ins >> checknum;
    	ins >> date;
    	while(ins.peek()=='\n' || ins.peek()=='\r'){
    		ins.ignore();
    	}
    	getline(ins, payto);
    	ins >> amount;
	/* You are to write the implementation of this function to read 
	from the keyboard or a file. Remember to use getline to read the 
	payto.  */

    	} 
    void Check::output(std::ostream& outs)const{

    	// this allows for the program to output the correct text to the screen and to the 
    	// file so that you dont get the extra text in the file becausse we dont want that.

    	if(&outs == &cout){
    		outs << "Number: " << checknum << endl;
    		outs << "Date: " << date << endl;
    		outs << "Pay To: " << payto << endl;
    		outs << "Amount: " << amount << endl;
    	}
    	else{
    		outs << checknum << endl;
    		outs << date << endl;
    		outs << payto << endl;
    		outs << amount << endl;
    	}
	/* You are to write the implementation of this function to write 
	to the monitor or to a file. Remember not to put labels into the 
	file.*/

	}

ostream& operator << (ostream& outs, const Check& c){
        c.output(outs);
        return outs;
}

istream& operator >> (istream& ins, Check& c){
        c.write_check(ins);
        return ins;
}


