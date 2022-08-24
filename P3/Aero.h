/* Aero class
 * One of the concrete products made by AeratedChocolate (factory)
 */
#pragma once
#include <iostream>
#include <string>
#include "AeratedChocolate.h"

class Aero : public AeratedChocolate{
    public:
        Aero(std::string manufacturer, std::string type, int bubbles): AeratedChocolate(manufacturer, type, bubbles){}
};
