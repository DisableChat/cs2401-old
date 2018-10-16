// Wesley Ryder
// 9-9-17
// lab 4

#ifndef RIP
#define RIP

#include <iostream>
#include <algorithm>

class Numbers{
	public:
		Numbers();
		void resize();
		void remove_last();
		void display(std::ostream& cout)const;
		void add(unsigned long);

	private:
		unsigned long *data;
		std::size_t used;
		std::size_t capacity;
};

Numbers::Numbers(){
	capacity = 5;
	used = 0;
	data = new unsigned long[capacity];
}

void Numbers::resize(){
	unsigned long *tmp;
	tmp = new unsigned long[capacity + 5];
	std::copy(data, data + used, tmp);
	delete[]data;
	data = tmp;
	capacity += 5;
}

void Numbers::remove_last(){
	used--;
}

void Numbers::display(std::ostream& cout)const{
	for(int i = 0; i < used; i++){
		std::cout << data[i] << " ";
	}
}

void Numbers::add(unsigned long num){
	if(used == capacity){resize();}
	data[used] = num;
	used++;

}



#endif