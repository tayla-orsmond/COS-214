/*
* The ConfectioneryFactory class
* Abstract class
* Contains the basic functionality to produce chocolate and aerated chocolate
*/
#pragma once
#include <iostream>
#include "Confectionery.h"

class ConfectioneryFactory{
    public:
        ConfectioneryFactory();
        ~ConfectioneryFactory();
        //factoryMethods to be implemented in concrete factories
        virtual Confectionery * createChocolate(bool slab) = 0;
        virtual Confectionery * createAeratedChocolate(int bubblespccm) = 0;
};