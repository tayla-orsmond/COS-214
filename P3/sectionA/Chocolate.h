/* The Chocolate class
* Concrete class
* Inherits from Confectionery and implements the 
* methods needed to create chocolate concrete
* objects.
*/
#pragma once
#include <iostream>
#include <string>
#include "Confectionery.h"

class Chocolate : public Confectionery{
    public:
        Chocolate(std::string, double, bool);//manufacturer, price, slab
        virtual ~Chocolate();
        std::string getDescription();//prints parent + if is slab or not
        //getters and setters
        bool getSlab();
        void setSlab(bool);
    private:
        bool slab;//if is slab or not
};
