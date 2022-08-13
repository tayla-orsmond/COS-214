#include <iostream>
#include <string>
#include "Calculator.h"
using namespace std;
//Tayla Orsmond u21467456

int main(){
    //calculate and print the value of 741 / 13
    Calculator<int> * carl = new Calculator<int>(741, 13);
    cout<< carl->divide() << endl;
    delete carl;
    carl = NULL;
    //calculate and print the value of 127.58 + 54.971
    Calculator<double> * darl = new Calculator<double>(127.58, 127.58);
    cout<< darl->add() << endl;
    delete darl;
    darl = NULL;
    //calculate and print the value of "Hello" + "World" + "!"
    Calculator<string> * sarl = new Calculator<string>("Hello", "World");
    Calculator<string> * marl = new Calculator<string>(sarl->add(), "!");
    cout<< marl->add() << endl; 
    delete marl;
    delete sarl;
    marl = NULL;
    sarl = NULL;
    //calculate and print the value of "Hello" * "World" + "!"
    // Calculator<string> * thrarl = new Calculator<string>("Hello", "World");
    // Calculator<string> * karl = new Calculator<string>(thrarl->multiply(), "!");
    // cout<< karl->add() << endl; 
    // delete karl;
    // delete thrarl;
    // karl = NULL;
    // thrarl = NULL;

    return 0;
}