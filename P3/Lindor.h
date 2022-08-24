/* Lindor class
 * One of the concrete products made by Chocolate (factory)
 */
#pragma once
#include <iostream>
#include <string>
#include "Chocolate.h"

class Lindor : public Chocolate{
    public:
        Lindor(std::string manufacturer, std::string type, bool slab): Chocolate(manufacturer, type, slab){}
};