/* MilkyBar class
 * One of the concrete products made by Chocolate (factory)
 */
#pragma once
#include <iostream>
#include <string>
#include "Chocolate.h"

class MilkyBar : public Chocolate{
    public:
        MilkyBar(std::string manufacturer, bool slab, double price = 33.99): Chocolate(manufacturer, price, slab){}
};