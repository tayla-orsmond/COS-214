/*
* The Cadbury class
* Concrete class - Inherits from ConfectioneryFactory
* Contains functionailty to produce Cadbury chocolates
* - Dairy Milk (chocolate)
* - Dairy Milk Bubbly (aerated chocolate)
*/
#pragma once
#include <string>
#include "ConfectioneryFactory.h"
#include "DairyMilk.h"
#include "DairyMilkBubbly.h"

class Cadbury: public ConfectioneryFactory{
    public:
    Cadbury();
    ~Cadbury();
    Confectionery * createChocolate(bool);//slab
    Confectionery * createAeratedChocolate(int);//bubblespccm
};