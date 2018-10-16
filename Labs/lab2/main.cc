// Wesley Ryder
// CS2401
// Lab 2
// 9/5/17
// Description: to fix the given program in lab and to fix the b_sort function as well as other
// functions in the program so that the program sorts numbers correctly and then output them to 
// the file with "sorted" added.

/******************************************************
   A primitive main solution for lab2 - cs2401
*****************************************************/
#include<iostream>
#include<fstream>
#include "numlist.h"
using namespace std;

int main(){
     NumList num1;		// Declarying the variables
     int tmp;
     ifstream ifs;
     string filename;
     cout<<"Please enter the name of your number file.\n";
     cin>>filename;
     ifs.open(filename.c_str());
     if(ifs.fail()){
	cout<<"Input file failed to open.\n";
	return -1;
     }
     num1.load_from_file(ifs);
     ifs.close();
     num1.see_all();
     cout<<"Please enter three numbers to add to the list.\n";
     cin>>tmp;
     num1.insert(tmp); //1
     cin>>tmp;
     num1.insert(tmp); //2
     cin>>tmp;
     num1.insert(tmp); //3
     num1.b_sort();
     num1.see_all();
// here you will use the find function to find the . in the filename
// immediately before the . you will insert the word "sorted"
// the filename will now be changed so the following will save to the new 
// name -- this only takes two or three lines of code
     int found;					// added int found and then would search for the "." location and then would insert "sorted" after the filename.
     found = filename.find(".");
     filename.insert(found, "sorted");

     ofstream ofs(filename.c_str());
     num1.save_to_file(ofs);
     ofs.close();

return 0;
}


