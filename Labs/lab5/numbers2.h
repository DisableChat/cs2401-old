// Wesley Ryder
// 9/27/17
// Lab 5
// Description to further our knowledge about pointers but this time a pointer that points to an array
// holding two things of information.

#include<iostream>
#include<cstdlib>
using namespace std;
/* This class is so simple that it is really a lot like an old-fashioned C strut
   with the two data members being public and directly accessible by everything
*/

class simple{
    public:
        unsigned long num;
	unsigned long *sq;
};

class Numbers2{
    public:
    Numbers2(); // declarying functions and vars etc.
	~Numbers2();
	Numbers2(const Numbers2 &other); // had to add the coppy constructor.
	void insert(unsigned long item);
	void display();
	void operator = (const Numbers2& other);
	
    private:
	void resize();
	simple *data;
	size_t used, capacity;
};

Numbers2::Numbers2(){
	used = 0;
	capacity = 10;
	data = new simple[capacity];
}


// the resize function was harder because we had to now copy all of the information 
// in the array which this time instead of one thing is a value and the pointer.
// so we have to use a for loop.
void Numbers2::resize(){
	simple* tmp;
	capacity += 5;
	tmp = new simple[capacity];

	for(size_t i = 0; i < used; i++){
		tmp[i].num = data[i].num;
		tmp[i].sq = new unsigned long;
		*(tmp[i].sq) = *(data[i].sq);
	}

	for(size_t k = 0; k < used; k++){delete data[k].sq;}
	delete[] data;
	data = tmp;
	// copying is going to be more complicated this time because 
	// for each array element you will have to allocate the 
	//unsigned long which will hold its square

	// deleting the hold array will also be more complicated
}


// if used == capacity we resize and then we insert values we  want for the array
// in this case the num and the square of that num and then we increment.
void Numbers2::insert(unsigned long item){
	if(used == capacity){
	   resize();
	}
	data[used].num = item;
	data[used].sq = new unsigned long;
	*(data[used].sq) = item*item;
 	used++;
}

// Making a copy constructor requires us to again copy all the contents in teh array
// in this case being the pointer and the number so we used a for loop to do this.
Numbers2::Numbers2(const Numbers2 &other)
{
	used = other.used;
	capacity = other.capacity;
	data = new simple[capacity];
	for(size_t i = 0; i < used; i++){
		data[i].num = other.data[i].num;
		data[i].sq = new unsigned long;
		*(data[i].sq) = *(other.data[i].sq);
	}
}


void Numbers2::display(){
	for(size_t i = 0; i < used; i++)
	     cout<<"( "<<data[i].num<<","<<*(data[i].sq)<<" ) ";
	cout<<endl;
}

// for this we must first delete the contents inside the array and then we can delete the
// acutal data array. After that we just copy the info into the new spots.
void Numbers2::operator = (const Numbers2& other){
    // This is left up to the student
	if(this == &other){
	return;
	}

	if(capacity != other.capacity){
		for(size_t i = 0; i < used; i++){
		delete data[i].sq;
		}
	}
	delete[]data;
	capacity = other.capacity;
	data = new simple[capacity];
	used = other.used;
	for(size_t i = 0; i < used; i++){	
		data[i].num = other.data[i].num;
		data[i].sq = new unsigned long;
		*(data[i].sq) = *(other.data[i].sq);
	}
}

// almost same as regular destructor but this time we have to delete the data[i].sq.
// then we can delete[]data.

Numbers2::~Numbers2(){
	for(size_t i = 0; i < used; i++){
		delete data[i].sq; // this is used to delete the pointer 
	}
	delete[]data;
	cout<<"I'm melting!!!\n";
}

