/* The AeratedChocolate class
* Concrete class 
* Inherits from Confectionery and implements the 
* methods needed to create aerated concrete
* objects.
*/
#pragma once
#include <iostream>
#include <string>
#include "Confectionery.h"

class AeratedChocolate : public Confectionery{
    public:
        AeratedChocolate(std::string, double price, int);//manufacturer, price, bubblespccm
        virtual ~AeratedChocolate();
        std::string getDescription();//prints parent + bubblespccm
        //getters and setters
        int getBubblespccm();
        void setBubblespccm(int);
    private:
        int bubblespccm;//bubbles per cubic centimeter
};