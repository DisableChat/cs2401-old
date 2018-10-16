/**********************************************************************************
		Wesley Ryder
		11-14-17
		Project 5
		Description: This is the home class, It has a parent class with 5 child
			classes in it.
**********************************************************************************/
#include <iostream>
#include <list>
#include <fstream>
#include <string>

#ifndef HOME_H
#define HOME_H

// parent class home
class Home{
	public:
		Home();
		void virtual input(std::istream& ins) = 0;
		void virtual output(std::ostream& outs) = 0;
	protected:
		double temp;
};
// child class sloth that has some extra variables
class Sloth:public Home{
	public:
		Sloth();
		void input(std::istream& ins);
		void output(std::ostream& outs);
	private:
		bool hammock;
		std::string bed_color;
		int number_of_trees;
};
// child class bear that hold some different variables
class Bear:public Home{
	public:
		Bear();
		void input(std::istream& ins);
		void output(std::ostream& out);
	private:
		std::string size_of_cave;
		bool fire_place;
		std::string int_color;
		double lbs_of_meat_in_cave;
		int num_of_honeypots;
};
// child class cat that holds some extra variables
class Cat:public Home{
	public:
		Cat();
		void input(std::istream& ins);
		void output(std::ostream& out);
	private:
		int levels;
		std::string material;
		double length;
		double width;
		
};
// child class snake that holds some extra variables
class Snake:public Home{
	public:
		Snake();
		void input(std::istream& ins);
		void output(std::ostream& out);
	private:
		bool disco_ball;
		bool heat_lamp;
		std::string floor;
};
// child class monkey that has some different variables as well
class Monkey:public Home{
	public:
		Monkey();
		void input(std::istream& ins);
		void output(std::ostream& out);
	private:
		double feet;
		std::string color;
		std::string type;
		
};

#endif