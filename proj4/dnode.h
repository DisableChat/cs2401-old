/***************************************************************************

	Wesley Ryder
	CS2401 Proj 4
	10-22-17
	Description: This is header file for the class dnode.h where each node
		holds a datafield that has been templated so we can have different
		value types and it also contains two pointers one pointing to 
		previous and one pointing to next so we can make a doubly linked list. 

****************************************************************************/
#include<iostream>
#ifndef DNODE_H
#define DNODE_H


template<class T>
class Dnode{
	public:
		typedef T value_type;
		// constructor
		Dnode(T d = T(), Dnode* p = NULL, Dnode* n = NULL)
			{data_field = d; previous_ptr = p; next_ptr = n;}

		// mutator functions
		void set_data(T d){data_field = d;}
		void set_previous(Dnode* p){previous_ptr = p;}
		void set_next(Dnode* n){next_ptr = n;}

		//accesor functions
		T data()const{return data_field;}
		Dnode* next(){return next_ptr;}
		const Dnode* next()const{return next_ptr;}
		Dnode* previous(){return previous_ptr;}
		const Dnode* previous()const{return previous_ptr;}
	private:
		T data_field;
		Dnode* previous_ptr;
		Dnode* next_ptr;
};

#endif