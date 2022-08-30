/* DairyMilk class
 * One of the concrete products made by Chocolate (factory)
 */
#pragma once
#include <iostream>
#include <string>
#include "Chocolate.h"

class DairyMilk : public Chocolate{
    public:
        DairyMilk(bool slab, std::string manufacturer = "Cadbury", double price = 18.95): Chocolate(manufacturer, price, slab){}
        ~DairyMilk(){ std::cout<<"DairyMilk eaten.\n";}
};