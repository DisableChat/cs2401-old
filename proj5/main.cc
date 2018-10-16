/**********************************************************************************
		Wesley Ryder
		11-14-17
		Project 5
		Description: This is the main for my proj 5 where it displays a menu for
			the user so that they can add animal homes with different options for
			them to choose from.
**********************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <cctype>
#include "home.h"
using namespace std;

int menu();

int main(){
	ifstream fin;
	ofstream fout;
	string filename;
	int choice;
	char key;
	Home* tmp;
	list<Home*>::iterator it;
	list<Home*> list;

	fin.open("homes.txt");
	if(fin.fail()){
		cout << "Homes.txt was not found, creating a new homes.txt for user." << endl;
		filename = "homes.txt";
		fin.open(filename.c_str());
	}
	// loading from file with cases for which type of values I should load in depedning on key
	// asociated with the animal like sloth's key is S for example.
	else if(!fin.fail()){
		while(!fin.eof()){
			fin >> key;
			if(key == 'S'){
				tmp = new Sloth;
				tmp -> input(fin);
				list.push_back(tmp);
			}
			else if(key == 'B'){
				tmp = new Bear;
				tmp -> input(fin);
				list.push_back(tmp);
			}
			else if(key == 'C'){
				tmp = new Cat;
				tmp -> input(fin);
				list.push_back(tmp);
			}
			else if(key == 'K'){
				tmp = new Snake;
				tmp -> input(fin);
				list.push_back(tmp);
			}
			else if(key == 'M'){
				tmp = new Monkey;
				tmp -> input(fin);
				list.push_back(tmp);
			}
		}
		//this deletes the extra empty one that it puts on back of list
		list.pop_back();
	}
	fin.close();
	// menu for the user to choose from
	do{
		choice = menu();
		switch(choice){
			case 1:
				tmp = new Sloth;
				tmp -> input(cin);
				list.push_back(tmp);
				break;
			case 2:
				tmp = new Bear;
				tmp -> input(cin);
				list.push_back(tmp);
				break;
			case 3:
				tmp = new Cat;
				tmp -> input(cin);
				list.push_back(tmp);
				break;
			case 4:
				tmp = new Snake;
				tmp -> input(cin);
				list.push_back(tmp);
				break;
			case 5:
				tmp = new Monkey;
				tmp -> input(cin);
				list.push_back(tmp);
				break; 
			case 6:
				// making loop so it displays all of the homes in the list.
				cout << endl;
				it = list.begin();
				while(it != list.end()){
					(*it) -> output(cout);
					it++;
				}
				cout << endl;
				break;
			// this case saves the list to a file output.
			case 0:
				cout << "Thank you for using Animal Home Builder.\n";
				cout << "The program will now save your progress.\n";
				fout.open("homes.txt");
				for(it = list.begin(); it != list.end(); it++){
					(*it) -> output(fout);
				}
				fout.close();
				break;
			default:
				cout << "Not a valid choice!\n " << endl;
		}
	}while(choice != 0);
	return 0;
}
// int menu function so user can see what number corosponds to which option.
int menu(){
	int choice;
	cout << "Welcome to the animal home creator!" << endl;
	cout << "Choose which animal home you would like to add and customize from the options below: " << endl;
	cout << "1) Sloth home. " << endl;
	cout << "2) Bear home. " << endl;
	cout << "3) Cat home. " << endl;
	cout << "4) Snake home. " << endl;
	cout << "5) Monkey home. " << endl;
	cout << "6) Display Current Homes and setups." << endl;
	cout << "0) Save and Exit" << endl;
	cout << "Choice: ";
	cin >> choice;
	return choice;
}