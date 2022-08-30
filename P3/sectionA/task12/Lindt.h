/*
* The Lindt class
* Concrete class - Inherits from ConfectioneryFactory
* Contains functionailty to produce Lindt chocolates
* - Lindor (chocolate)
* - NONE (aerated chocolate)
*/
#pragma once
#include <string>
#include "ConfectioneryFactory.h"
#include "Lindor.h"

class Lindt: public ConfectioneryFactory{
    public:
    Lindt();
    ~Lindt();
    Confectionery * createChocolate(bool);//slab
    Confectionery * createAeratedChocolate(int);//bubblespccm
};