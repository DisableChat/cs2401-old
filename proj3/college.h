/*******************************************************************************
	Wesley Ryder
	CS2401 Proj 3
	10-10-17
	Description: This is the college class. This class is used to maniipulate
			the nodes in the menu. like adding, displaying, remove, etc. This 
			class essintially manipulates the nodes to change how they point 
			at eachother.
*******************************************************************************/

/*************************************************************************
      This file is borrowed heavily from Main/Savitch "Data Structures and
      Other Object Using C++," Chapter 5. It features a node class that 
      can be used in the construction of linked lists.
                John Dolan  		March 2009
*************************************************************************/

#ifndef COLLEGE_H
#define COLLEGE_H
#include "node.h"
#include <iostream>

class College{
	public:
		// Defualt constructor
		College(std::string n);

		// The big three
		College(const College& other);
		~College();
		College& operator = (const College& other); 

		void load(std::ifstream& fin);
		void save(std::ofstream& fout);
		void add(const course& c);
		void display(std::ostream& outs)const;
		void remove(const std::string& n);
		double hours()const;
		double gpa()const;
		

	private:
		std::string name;
		node* head;



};

#endif