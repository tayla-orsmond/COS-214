/* DairyMilk class
 * One of the concrete products made by Chocolate (factory)
 */
#pragma once
#include <iostream>
#include <string>
#include "Chocolate.h"

class DairyMilk : public Chocolate{
    public:
        DairyMilk(std::string manufacturer, bool slab, double price = 18.95): Chocolate(manufacturer, price, slab){}
};