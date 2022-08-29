/* Lindor class
 * One of the concrete products made by Chocolate (factory)
 */
#pragma once
#include <iostream>
#include <string>
#include "Chocolate.h"

class Lindor : public Chocolate{
    public:
        Lindor(std::string manufacturer, bool slab, double price = 44.95): Chocolate(manufacturer, price, slab){}
};