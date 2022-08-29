/* Aero class
 * One of the concrete products made by AeratedChocolate (factory)
 */
#pragma once
#include <iostream>
#include <string>
#include "AeratedChocolate.h"

class Aero : public AeratedChocolate{
    public:
        Aero(int bubbles, std::string manufacturer = "Nestle", double price = 16.99): AeratedChocolate(manufacturer, price, bubbles){}
        ~Aero(){ std::cout<<"Aero eaten.\n"; }
};
