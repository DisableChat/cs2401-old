// Wesley Ryder
// CS 2401 Lab 10
// 10-31-17
// description to learn how a Reverse polish notation calculator works.

/**********************************************************************
	Lab Assignment 9 - working with a stack
	It's sometimes tricky to set up the loop that reads the
 expression from the keyboard, so I am giving that to you. You have to
 fill in the rest of the main.
	John Dolan Fall 2016
 Ohio University
 Home of the Bobcats
 **********************************************************************/
#include <stack>
#include <iostream>
#include<cstdlib>
#include "calc_useful.h"
using namespace std;


int main(){
    char c;
    char tmp;
    int onenum, twonum;
    int count;
    bool continu = true;
    stack<int> nums;
    cout<<"Please enter your expression:\n";

    // note made a do while so it does loop while continue == true.
    do{
        c = cin.get(); // priming read for the sentinel loop.

        while(c != '\n'){
            if(isdigit(c)){
                cin.putback(c);
                cin >> onenum;
                cout << onenum << endl;
                nums.push(onenum);
                // stack operation here.
            }
            else if(isop(c)){
                if(!nums.empty()){
                    onenum = nums.top();
                    nums.pop();
                    if(!nums.empty()){
                        twonum = nums.top();
                        nums.pop();
                        int tmp;
                        if(c=='+' || c=='*'){
                            tmp = evaluate(onenum,twonum,c);
                            cout << tmp << endl;  
                        }

                        else if(c=='-' || c=='/'){
                            tmp = evaluate(twonum,onenum,c);
                            cout << tmp <<endl;
                        }

                        nums.push(tmp);
                        onenum = nums.top();
                    }
                    // producing error message.
                    else{
                        cout << "Error. Insufficient operators for operands.\n";
                        return -1;
                    }  
                }
                // if the stack is empty here you have an error.
                if(nums.empty()){
                    cout << "Stack is empty error" << endl;
                    return -1;
                }
                // here is where you have to pop a couple of numbers,
                // apply the operator to the numbers
                // and then push the result back into the stack
                
            }
            c = cin.get(); // reading at the bottom of the sentinel loop
        }

        // this your final answer in the stack. and should be the only number left in stack at this point.
        if(nums.empty()){
            cout << "Error. Insufficient operators for operands.\n";
            return -1;
        }

        //checking to see if only one number is in the stack so if not empty give errror message.
        nums.pop();
        if(!nums.empty()){
            cout << "More than one number left in stack error" << endl;
            return -1;
        }

        cout << "The answer is: " << onenum << endl;
        cout << "Enter another equation?(y or n)";

        // made it so if you wanted to do enter another equation that you had to type y and then the equation.
        cout << " **NOTE** If you choose 'y', please enter 'y' first and then follow that with the equation, so type: y 'equation'" << endl;
        cin >> tmp;
        if(tmp == 'y' || tmp == 'Y'){
            continu=true;
        }
        else{
            continu = false;
        }
    }
    while(continu == true);
    
    return 0;
}
