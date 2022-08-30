/* Lindor class
 * One of the concrete products made by Chocolate (factory)
 */
#pragma once
#include <iostream>
#include <string>
#include "Chocolate.h"

class Lindor : public Chocolate{
    public:
        Lindor(bool slab, std::string manufacturer="Lindt", double price = 44.95): Chocolate(manufacturer, price, slab){}
        ~Lindor(){ std::cout<<"Lindor eaten.\n"; }
};