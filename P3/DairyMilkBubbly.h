/* DairyMilkBubbly class
 * One of the concrete products made by AeratedChocolate (factory)
 */
#pragma once
#include <iostream>
#include <string>
#include "AeratedChocolate.h"

class DairyMilkBubbly : public AeratedChocolate{
    public:
        DairyMilkBubbly(std::string manufacturer, int bubbles, double price = 20.49): AeratedChocolate(manufacturer, price, bubbles){}
};
