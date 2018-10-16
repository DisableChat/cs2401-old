/********************************************************************* 
Wesley Ryder
9-21-17
Proj 2
Description: This is the implementation file for the class friend.
having an object friend being something that holds the name and date.
This is used later on in the class fbfriends. 
*********************************************************************/
#include "friend.h"
using namespace std;

//creating a defualt constructor.
Friend::Friend(){
	name = "NO_USER";
	bday = Date(1,1,1000);

}

// accesor fucntion for the friend name
string Friend::get_name()const{
	return name;
}

//accesor function for the bday
Date Friend::get_bday()const{
	return bday;
}


// inputs the names and dates of the friends from the given txt file.
// also uses fixes the problem with microsofts backslash. it reads
// untill the end of the file.
void Friend::input(istream& ins){
	while(ins.peek() == '\n' || ins.peek() == '\r'){
		ins.ignore();
	}
	getline(ins, name);
	ins >> bday;
}

// outputs the name and bday of the friend.
void Friend::output(ostream& outs)const{
	outs << name << endl;
	outs << bday << endl;
}

// overloading the == operator for bool expressions.
bool Friend::operator == (const Friend& other)const{
	return name == other.name && bday == other.bday;
}

// overloading the != opperator for the bool expression.
bool Friend::operator != (const Friend& other)const{
	return name != other.name && bday != other.bday;
}

// overloading the >> operator so we can use it with the object
// so we can correctly input an object.
istream& operator >>(istream& ins,Friend& f){
	f.input(ins);
	return ins;
}

// overlaoding the << operator so we can use it with the object so we
// can correctly output an object.
ostream& operator <<(ostream& outs,const Friend& f){
	f.output(outs);
	return outs;
}