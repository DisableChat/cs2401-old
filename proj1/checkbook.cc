/***************************************************************
Wesley Ryder
CS2401 Proj 1
Sep-11-2017
Description: This is the implementaion file for the checkbook 
class. for more information go to the checkbook.h header file.
***************************************************************/


#include "checkbook.h"
using namespace std; 

// this loads from file by inputing the balance first and then inserting
// parts of the array untill reaching the end of the file.

void Checkbook::load_from_file(istream& ifs){
	ifs >> balance;
	ifs >> array[used];
	while(! ifs.eof()){
		used++;
		ifs >> array[used];
		
	} 
}

// Adds depposit to total checking balance.

void Checkbook::deposit(double depamount){
	balance += depamount;

//the write_check function allows user to enter check and checks if the check 
// number already exists, if so then it prompts user to enter new check. The 
// function also updates the balance.

}
void Checkbook::write_check(istream& cin){
	Check tmp;
	bool done = false; // declaring variables for my loop
	int track;

	cout << "Enter Checknum, Check Date, Payee and Amount " << endl;
	
	while(!done){	// making while loop while not done
		track = 0; 
		cin >> tmp;   //putting cin before for loop.
		for (int i = 0; i < used; i++){	
			if(tmp.get_num() == array[i].get_num()){
				cout << "Check Number Already Used! " << endl; 
				cout << "Enter Valid Checknum, Check Date, Payee and Amount" << endl;	
				track++;
			}
		}
		// this is outside for loop so if there already is a check number then adds 
		// to the track variable and makes it go through the while loop again. due to the
		// if statment.

		if (track == 0){done = true;} 
	}									
	array[used] = tmp;
	used++;
	balance = balance - tmp.get_amount(); 
}

// returns balance

double Checkbook::get_balance()const{
	return balance;
}

// show_all function shows all checks in checkbook

void Checkbook::show_all(ostream& outs)const{
	for (int i = 0; i < used; i++){
		outs << array[i] << endl;
	}
}

// the remove function removes the check the user requests and 
// puts the money back in the user account.

void Checkbook::remove(int rmnum){
	for(int i = 0; i < used; i++){
		if(rmnum == array[i].get_num()){
			balance += array[i].get_amount();
			array[i] = array[used - 1];
			used--;
		}
	}
}

// Number_sort just sorts the checkbook numbers in numerical order
// using a bubble sort.

void Checkbook::number_sort(){
	Check tmp;
	bool done = false;
	size_t i;
	while(!done){
		done = true;
		for(i = 0; i < used -1; i++){
			if(array[i].get_num() > array[i + 1].get_num()){
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				done = false;
			}
		}
	}
}

// same idea as other sorts but this time its sorting by date.
// and sets the bool variable as false untill it finishes through
// the bubble sort.

void Checkbook::date_sort(){
	Check tmp;
	bool done = false;
	size_t i;
	while(!done){
		done = true;
		for(i = 0; i < used -1; i++){
			if(array[i].get_date() > array[i + 1].get_date()){
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				done = false;
			}
		}
	}
}

// the average function just uses a for loop to get through the array to 
// add all the total amount and then divides by the used varaible to get 
// the average of  the checks written.

double Checkbook::average()const{
	double total = 0;
	double average = 0;
	for (int i = 0; i < used; i++){
		total += array[i].get_amount();
	}

	average = total/used;

	//rounding output of average
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	return average;
}

// again same method as the date sort, number sort just sorting payto through
// the array this time.

void Checkbook::payto_sort(){
	Check tmp;
	bool done = false;
	size_t i;
	while(!done){
		done = true;
		for(i = 0; i < used -1; i++){
			if(array[i].get_payto() > array[i + 1].get_payto()){
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				done = false;
			}
		}
	}
}

// uses for loop to go through the array and cout all of the array.

void Checkbook::show(string payto_find)const{ 
    for(int i = 0; i < used; i++){
        if(array[i].get_payto() == payto_find){
            cout << array[i];
        }
    }
} 

// the save function goes through the array and outputs it to a file
// this file is considered the backup file.

void Checkbook::save(ostream& ofs)const{
	ofs << balance << endl;
	for(int i = 0; i < used; i++){
		ofs << array[i];
	}
}