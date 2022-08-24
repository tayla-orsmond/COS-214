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
        AeratedChocolate(std::string, std::string, int);
        std::string getDescription(int);
        int getBubblespccm();
        void setBubblespccm(int);
    private:
        int bubblespccm;
};