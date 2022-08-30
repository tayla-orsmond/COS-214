/*
* The Nestle class
* Concrete class - Inherits from ConfectioneryFactory
* Contains functionailty to produce Nestle chocolates
* - MilkyBar (chocolate)
* - Aero (aerated chocolate)
*/
#pragma once
#include <string>
#include "ConfectioneryFactory.h"
#include "MilkyBar.h"
#include "Aero.h"

class Nestle: public ConfectioneryFactory{
    public:
    Nestle();
    ~Nestle();
    Confectionery * createChocolate(bool);//slab
    Confectionery * createAeratedChocolate(int);//bubblespccm
};