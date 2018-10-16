/***************************************************************************

	Wesley Ryder
	CS2401 Proj 4
	10-22-17
	Description: This is header file for the class dlist.h  this file also
		contains the node iterator which is used to transverse the list in 
		the program This way we can manipulate the list and use the itterator
		to transverse the doubly linked list. This also involves a templated
		class so we can have different value types. The dlist class allows 
		us to connect all the dnodes to make a doubly linked list.

****************************************************************************/

#include <iostream>
#include "dnode.h"
#ifndef LIST_H
#define LIST_H

// foward decleraton for the dlist class
template<class T>
class dlist;
template<class T>
class node_iterator{
	public:
		// defualt constructor
		node_iterator(Dnode<T> *init = NULL){current = init;}
		// now node_iterator can have access to t he head tail and the count.
		friend class dlist<T>;
		//overloaded operators for the node iterator
		T operator * (){return current -> data();}
		bool operator != (const node_iterator& other){return current != other.current;}
		bool operator == (const node_iterator& other){return current == other.current;}
		node_iterator operator ++(){current = current -> next(); return *this;}
		node_iterator operator ++(int){node_iterator original(*this);current = current -> next(); return original;}
		node_iterator operator --(){current = current -> previous(); return *this;}
		node_iterator operator --(int){node_iterator original(*this);current = current -> previous(); return original;}
	private:
		Dnode<T>* current;
};


//class Dnode;
template<class T>
class dlist{
	public:
		typedef node_iterator<T> iterator;

		//defualt constructor
		dlist();
		
		// The big 3;
		dlist(const dlist& other);
		~dlist();
		dlist& operator = (const dlist& other);

		// itterator functions
		iterator begin(){return iterator(head);}
		iterator end(){return iterator(NULL);}
		iterator r_begin(){return iterator(tail);}
		iterator r_end(){return iterator(NULL);}

		// functions for manipulating the list
		void rear_insert(T item);
		void front_insert(T item);
		void front_remove();
		void rear_remove();
		void remove(iterator it);
		void insert_before(iterator it, T item);
		void insert_after(iterator it, T item);
		void show();
		void reverse_show();
		int size();
	private:
		size_t count;
		Dnode<T>* head;
		Dnode<T>* tail;
};

#include "dlist.template"
#endif