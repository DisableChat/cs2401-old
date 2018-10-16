/********************************************************************
Wesley Ryder
CS2401 Proj 1
Sep-11-2017
Description: header file for check class. This header file was
provided by Dolan. further information can be found in next comment
box
*********************************************************************/


/***********************************************************************
    This is the header file for a check class. It holds the information 
for a single check, which is the check number, the date it was written, 
to whom it was written and the amount. There are two ways of inputting 
into the check, the write_check function and the >> operator. There are 
also two ways of outputting the check, the output function and the << 
operator.
    Checks cannot be written for less than $0.01.
  	John Dolan	Ohio University		September 2017
************************************************************************/

#ifndef CHEESEY			//Safeguard
#define CHEESEY

#include <iostream>
#include <string>
#include "date.h"

class Check{
    public:
	Check(Date d = Date(1,1,1900), std::string p = "VOID", 
		int num = 1, double amt = 0);
    // Input and output functions
	void write_check(std::istream& ins);
	void output(std::ostream& outs)const;
    // Accessor functions
	double get_amount()const {return amount;}	 
    Date get_date()const {return date;}
	std::string get_payto()const {return payto;}
	int get_num()const {return checknum;}
    private:
	int checknum;
	Date date;
	std::string payto;
	double amount;
};

std::ostream& operator << (std::ostream& outs, const Check& c);

std::istream& operator >> (std::istream& ins, Check& c);


#endif
