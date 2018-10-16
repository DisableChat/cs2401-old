/**********************************************************************************
	Wesley Ryder
	9-21-17
	Proj 2
	Description: This is the implementation file for the fbriends class. This
	includes the destructor, copy constructor, and the overloaded assignment 
	opperator.  More info can be found in the header file of fbfriends.
**********************************************************************************/

#include <iostream>
using namespace std;
#include "fbfriends.h"


// Defualt Constructor
FBFriends::FBFriends(){
	capacity = 5;
	used = 0;
	data = new Friend[capacity];
	current_index = 0;
}

// Destructor Function one of the big 3.
FBFriends::~FBFriends(){
	delete[]data;
}

// Copy function of FBFriends One of the big 3.
FBFriends::FBFriends(const FBFriends& other){
	used = other.used;
	capacity = other.capacity;
	data = new Friend[capacity];
	copy(other.data, other.data + used, data);
}

// assignment operrator function one of the big 3.
// this is so we can set two objects equal two eachother without pointing to
// same memory spot.
void FBFriends::operator = (const FBFriends& other){
	if(this == &other){
		return;
	}
	if(capacity != other.capacity){
		delete[]data;
		capacity = other.capacity;
		data = new Friend[capacity];
	}
	used = other.used;
	copy(other.data, other.data + used, data);
}

// if used doesnt equal 0 then starts at current index.
void FBFriends::start(){
	if(used != 0){
		current_index = 0;
	}
}

// Advance function advances one spot in looking through freinds
// but only if it is an item.
void FBFriends::advance(){
	if(is_item() == true){
		current_index++;
	}
}

// Checks to make sure current index is an actual item.
// done by if current index is less than used then its valid
// item.
bool FBFriends::is_item(){
	if(current_index < used){
		return true;
	}
	else{return false;}
}

// Current function just returns the current index of data[]
// but only if it is an item before hand.
Friend FBFriends::current(){
	if(is_item() == true){
		return data[current_index];
	}
}

// Remove function removes current index in data[]
// Remove current basically is just a bubble sorth that moves all the items to the left starting
// at current index. this way they shift one spot in the index to the left. "removing" the targeted
// spot or in this case "current index".
void FBFriends::remove_current(){
	Friend tmp;
	size_t i = current_index;
	
	if(is_item() == true){
		current();
		for (i; i < used; i++){
			tmp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = tmp;
		}
		used--;
	}
}

// Insert function allows user to insert a friend into the array. This  is done moving everything to the right
// one index and creating a space for the inserted friend at its targeted location.
void FBFriends::insert(const Friend& f){
	Friend tmp;
	Friend tmp2;
	size_t i = used;

	// this fixes the issue of inserting friend (option one in menu)
	if(is_friend(f) == true){
		cout << "Already in list." << endl;
	}

	// reisize if capacity would be reached by adding another friend
	if(used + 1 == capacity){
		resize();
	}

	// inserting loop for when walking through list of friends
	if(is_item() == true && is_friend(f) == false){
		current();
		used++;
		tmp2 = current();
		for (i; i > current_index; i--){
			tmp = data[i + 1];
			data[i + 1] = data[i];
			data[i] = tmp; 
		}
		data[current_index +1] = tmp2;
		data[current_index] = f;
	}

	// inserting friend for first spot in index.
	if(is_item() == false && is_friend(f) == false){
		used++;
		data[current_index] = f;
	}
}


// Same as insert function but this time we are attaching behind current index. So we shift everything to the right again
// but a space is made so you can attach the friend.
void FBFriends::attach(const Friend& f){
	Friend tmp;
	Friend tmp2;
	size_t i = used;
	
	if(used + 1 == capacity){
		resize();
	}

	// ataches to current index(after current index) case if friends are in list
	if(is_item() == true){
		current();
		used++;
		tmp2 = data[current_index + 1];
		for (i; i > current_index + 1; i--){
			tmp = data[i + 1];
			data[i + 1] = data[i];
			data[i] = tmp; 
		}
		data[current_index + 2] = tmp2;
		data[current_index + 1] = f;
	}

	// case for if no friends are in list
	if(is_item() == false){
		used++;
		data[used - 1] = f;
	}
}

// This function shows all friends in array by using a for loop.
void FBFriends::show_all(ostream& outs)const{
	for(int i = 0; i < used; i++){
		outs << data[i] << endl;
	}
}

// Bday sort sorts the bdays in order from earliest birthday to lastest. This is done 
// using a while, for and if loop.
void FBFriends::bday_sort(){
	Friend tmp;
	size_t i;
	bool done = false;

	while(!done){
		done = true;
		for(i = 0; i < used - 1; i++){
			if(data[i].get_bday() > data[i + 1].get_bday()){
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
				done = false;
			}
		}
	}
}

// Find_function just finds the friend youre looking for and returns their info so you can see their birthday
// it also tells user if friend does not exist.
Friend FBFriends::find_friend(const string& name)const{
	size_t i = 0;
	bool tmp = false;
	Friend ftmp = Friend();

	for(i; i < used; i++){
		if(data[i].get_name() == name){
			cout <<  "Found your friend!" << endl;
			return data[i];
			tmp = true;
		}
	}
	if(!tmp){
		cout << "Friend not found!" << endl;
		return ftmp;
	}
}

//  Is_friend function returns if freind is true or false. So we can use it to confirm
//  if a friend already exists.
bool FBFriends::is_friend(const Friend& f)const{
	bool tmp = false;
	for(size_t k = 0; k < used; k++){
		if(data[k] == f){
			tmp = true;
		}
	}
	if(tmp == true){return true;}
	else{return false;}
}

// Loads from file the names and dates of all friends
void FBFriends::load(istream& ins){
	ins >> data[used];
	while(! ins.eof()){
		used++;
		if(used == capacity){
			resize();
		}
		ins >> data[used];
	}
}

// outputs a save file of what you have done to the list after youre done with main.
void FBFriends::save(ostream& outs){
	for(int i = 0; i < used; i++){
		outs << data[i];
	}
}

// Resize function allows the memory to be dynamic so we can make the array larger depending on how many friends we have.
void FBFriends::resize(){
	Friend *tmp;
	tmp = new Friend[capacity + 5];
	copy(data, data + used, tmp);
	delete[]data;
	data = tmp;
	capacity += 5;
}
