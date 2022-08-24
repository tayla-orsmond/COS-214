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
        Chocolate(std::string, std::string, bool);
        ~Chocolate();
        std::string getDescription(bool);
        bool getSlab();
        void setSlab(bool);
    private:
        bool slab;
};
