#include <iostream>
#include "ClassA.h"
#include "ClassB.h"
#include "ClassC.h"
#include "ClassD.h"
#include "ClassE.h"
using namespace std;

int main (){
    ClassE * e = new ClassE();
    cout<< "\n---\n";
    ClassC * c = new ClassC();
    cout<< "\n---\n";
    delete e;
    delete c;
    e = NULL;
    c = NULL;
    return 0;
}