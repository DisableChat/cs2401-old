/**********************************************************************************
		Wesley Ryder
		11-14-17
		Project 5
		Description: This is the implementation for the home.cc class, where it 
			holds the animals defualt constructors and their corrosponding 
			input and output function (there is a difference in console out and 
			file out same with input.) So the distinctions have been made for input
			and output functions of the child classes.
**********************************************************************************/

#include <iostream>
#include "home.h"
#include <fstream>
using namespace std;

// Defualt constructor for home
Home::Home(){
	temp = 0.0;
}

// defualt contructor for sloth
Sloth::Sloth(){
	hammock = false;
	bed_color = "N/A";
	number_of_trees = 0;
}

// defualt constructor for bear
Bear::Bear(){
	size_of_cave = "N/A";
	fire_place = false;
	int_color =  "N/A";
	lbs_of_meat_in_cave = 0.0;
	num_of_honeypots = 0;
}

// defualt constructor for cat
Cat::Cat(){
	levels = 0;
	material = "N/A";
	length = 0;
	width = 0;
}

// defualt contructor for snake
Snake::Snake(){
	disco_ball = false;
	heat_lamp = false;
	floor = "N/A";
}

// defualt constructor for monkey
Monkey::Monkey(){
	feet = 0;
	color = "N/A";
	type = "N/A";
}

// sloth input function also takes care of situation for file or console input/output.
// this is the same trend with rest of classes regarding input and output.
void Sloth::input(istream& ins){
	char ans;
	if(&ins == &cin){
		cout << "What temperature would you like your house to be at? (Fahrenheit)\n";
		ins >> temp;
		cout << "Would you like a hammock for your house (Y/N)?\n";
		ins >> ans;
		ans = toupper(ans);
		if(ans == 'Y'){
			hammock = true;
		}
		else{hammock = false;}
		cout << "What color bed would you like?\n";
		ins >> bed_color;
		cout << "How many small trees do you want in your house so you are be able to climb?\n";
		ins >> number_of_trees;
	}
	else{
		ins >> temp;
		ins >> hammock;
		ins >> bed_color;
		ins >> number_of_trees;
	}
}

// sloth output function
void Sloth::output(ostream& outs){
	if(&outs == &cout){
		cout << "Home Type: Sloth" << endl;
		cout << "Indoor temperature: " << temp << "F" << endl;
		cout << "Has Hammock: ";
		if(hammock == true){
			outs << "true" << endl;
		}
		else{outs << "false" << endl;}
		cout << "Bed color: " << bed_color << endl;
		cout << "Number of trees to climb: " << number_of_trees << endl;
	}
	else{
		outs << 'S';
		outs << "\n";
		outs << temp;
		outs << "\n";
		outs << hammock;
		outs << "\n";
		outs << bed_color;
		outs << "\n";
		outs << number_of_trees;
		outs << "\n";
	}
}

// bear input function
void Bear::input(istream& ins){
	char ans;
	if(&ins == &cin){
		cout << "What temperature would you like your house to be at? (Fahrenheit)\n";
		ins >> temp;
		cout << "Size of Cave? (small, medium large):\n";
		ins >> size_of_cave;
		cout << "Would you like a fire place for your cave? (Y/N)\n";
		ins >> ans;
		ans = toupper(ans);
		if(ans == 'Y'){
			fire_place = true;
		}
		else{fire_place = false;}
		cout << "Color for intererior of cave walls?\n";
		ins >> int_color;
		cout << "Lbs of meat you want in cave for snacking on?! (since you're a bear)\n";
		ins >> lbs_of_meat_in_cave;
		cout << "Number of honey pots for decoration?\n";
		ins >> num_of_honeypots;
	}
	else{
		ins >> temp;
		ins >> size_of_cave;
		ins >> fire_place;
		ins >> int_color;
		ins >> lbs_of_meat_in_cave;
		ins >> num_of_honeypots;
	}
}

// bear output function
void Bear::output(ostream& outs){
	if(&outs == &cout){
		cout << "Home Type: Bear " << endl;
		cout << "Indoor temperature: " << temp << "F" << endl;
		cout << "Size of cave: " << size_of_cave << endl;
		cout << "Fire Place: ";
		if (fire_place == true){
			outs << "true" << endl;
		}
		else{outs << "false" << endl;}
		cout << "Color of intererior walls: " << int_color << endl;
		cout << "Lbs of meat in cave (because you're a bear): " << lbs_of_meat_in_cave << endl;
		cout << "number of honey pots for decoration: " << num_of_honeypots << endl;
	}
	else{
		outs << 'B';
		outs << "\n";
		outs << temp;
		outs << "\n";
		outs << size_of_cave;
		outs << "\n";
		outs << fire_place;
		outs << "\n";
		outs << int_color;
		outs << "\n";
		outs << lbs_of_meat_in_cave;
		outs << "\n";
		outs<< num_of_honeypots;
		outs << "\n";
	}
}

// cat input function
void Cat::input(istream& ins){
	if(&ins == &cin){
		cout << "What temperature would you like your house to be at? (Fahrenheit)\n";
		ins >> temp;
		cout << "Number of levels in cat tree/house?\n";
		ins >> levels;
		cout << "Material cat tree/house is made out of?\n";
		ins >> material;
		cout << "Litter box Length (in)\n";
		ins >> length;
		cout << "Litter box width (in)\n";
		ins >> width;
	}
	else{
		ins >> temp;
		ins >> levels;
		ins >> material;
		ins >> length;
		ins >> width; 
	}
}

// cat output function
void Cat::output(ostream& outs){
	if(&outs == &cout){
		cout << "Home Type: Cat" << endl;
		cout << "Indoor temperature: " << temp << "F" << endl;
		cout << "Number of Levels: " << levels << endl;
		cout << "Material: " << material << endl;
		cout << "Litter box length (in): " << length << endl;
		cout << "Litter box width (in): " << width << endl;
	}
	else{
		outs << 'C';
		outs << "\n";
		outs << temp;
		outs << "\n";
		outs << levels;
		outs << "\n";
		outs << material;
		outs << "\n";
		outs << length;
		outs << "\n";
		outs << width; 
		outs << "\n";
	}
}

// snake input function
void Snake::input(istream& ins){
	char ans;
	char ans2;
	if(&ins == &cin){
		cout << "What temperature would you like your house to be at? (Fahrenheit)\n";
		ins >> temp;
		cout << "Do you want a disco ball? (Y/N)\n";
		ins >> ans;
		ans = toupper(ans);
		if(ans == 'Y'){
			disco_ball = true;
		}
		else{disco_ball = false;}
		cout << "Do you want a heat lamp? (Y/N)\n";
		ins >> ans2;
		ans2 = toupper(ans);
		if(ans2 == 'Y'){
			heat_lamp = true;
		}
		else{heat_lamp = false;}
		cout << "What type of material do you want for your floor? (ie mulch, dirt, carpet etc.)\n";
		ins >> floor;
	}
	else{
		ins >> temp;
		ins >> disco_ball;
		ins >> heat_lamp;
		ins >> floor;
	}
}

// snake output function
void Snake::output(ostream& outs){
	if(&outs == &cout){
		cout << "Home Type: Snake" << endl;
		cout << "Indoor temperature: " << temp << "F" << endl;
		cout << "Disco Ball: ";
		if (disco_ball == true){
			cout << "true" << endl;
		}
		else{outs << "false" << endl;}
		cout << "Heat Lamp: ";
		if (heat_lamp == true){
			cout << "true" << endl;
		}
		else{outs << "false" << endl;}
		cout << "Material floor is made out of: " << floor << endl;
	}
	else{
		outs << 'K';
		outs << "\n";
		outs << temp;
		outs << "\n";
		outs << disco_ball;
		outs << "\n";
		outs << heat_lamp;
		outs << "\n";
		outs << floor;
		outs << "\n";	
	}
}

// monkey input function
void Monkey::input(istream& ins){
	if(&ins == &cin){
		cout << "What temperature would you like your house to be at? (Fahrenheit)\n";
		ins >> temp;
		cout << "How tall of a jungle gym do you want? (ft)\n";
		ins >> feet;
		cout << "What color loft do you want to sleep on?\n";
		ins >> color;
		cout << "What type of food depsenser do you want? (ie banana, apple, etc) \n";
		ins >> type;
	}
	else{
		ins >> temp;
		ins >> feet;
		ins >> color;
		ins >> type;
	}
}

// m onkey output function
void Monkey::output(ostream& outs){
	if(&outs == &cout){
		cout << "Home Type: Monkey" << endl;
		cout << "Indoor temperature: " << temp << "F" << endl;
		cout << "Height of Jungle gym: " << feet << endl;
		cout << "Color of loft: " << color << endl;
		cout << "Type of food dispenser: " << type << endl;
	}
	else{
		outs << 'M';
		outs << "\n";
		outs << temp;
		outs << "\n";
		outs << feet;
		outs << "\n";
		outs << color;
		outs << "\n";
		outs << type;
		outs << "\n";
	}
}