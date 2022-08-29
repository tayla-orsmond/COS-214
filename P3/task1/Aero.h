/* Aero class
 * One of the concrete products made by AeratedChocolate (factory)
 */
#pragma once
#include <iostream>
#include <string>
#include "AeratedChocolate.h"

class Aero : public AeratedChocolate{
    public:
        Aero(std::string manufacturer, int bubbles, double price = 16.99): AeratedChocolate(manufacturer, price, bubbles){}
};
