#ifndef CLASS_D
#define CLASS_D

#include <iostream>
#include "ClassA.h"
#include "ClassB.h"
using namespace std;
//Tayla Orsmond u21467456

class ClassD: public ClassB, public ClassA{
    public:
    ClassD();
    virtual ~ClassD();
};

#endif