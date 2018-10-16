//Wesley Ryder
// CS2401 LAB 1 MyTime.cc file
// Aug 29 2017
// This is the header file for lab1 project
// need doucumentation for each member function - similar to your last
// project

#include <iostream>
#include <cstdlib>
#include <iomanip>
class MyTime
{   
  public:

    // CONVERT THESE CONSTRUCTORS INTO A SINGLE CONSTRUCTOR THAT USES 
    // DEFAULT ARGUMENTS
    MyTime(int h = 0, int m = 0);   //single constructor with two arguments hours and minutes
   
      
    void Reset(int h, int m);    
   
    MyTime operator + (const MyTime& t1)const; // overloading the "+" opperator so we can add objects
 
    MyTime operator - (const MyTime& t1)const; // overloading the "-" opperator so we can subtract objects
 
    MyTime operator * (int num)const;   // overloading the "*" opperator so we can multiply objects

    MyTime operator / (int num)const;   // overloading the "/" opperator so we can divide objects

    bool operator == (const MyTime& t1)const;   // overloading the "==" opperator to be able to compare times

    bool operator < (const MyTime& t1)const;    // overloading the "<" opperator so we can compare times

    bool operator <= (const MyTime& t1)const;   // overloading the "<" opperator so we can compare times and see if theyre less than or equal

    void input();       //input and out put functions     

    void output()const;

    int get_hours() const{return hours;}  // accessor functions
    int get_minutes() const{return minutes;}
   
  private:
      void simplify();
      int hours;      // hours can be > 24   // variables hours and times
      int minutes;   // 0 <= minutes <= 59
 };
   
	std::istream& operator >>(std::istream& ins, MyTime& t1);  // opperator overloading but not inside class.
    
	std::ostream& operator <<(std::ostream& outs, const MyTime& t1); // opperator overlaoding but not inside class.
