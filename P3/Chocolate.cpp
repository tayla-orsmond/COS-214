#include "Chocolate.h"
//constructor
Chocolate::Chocolate(std::string manufacturer, double price, bool slab) : Confectionery(manufacturer, "Chocolate", price){
    this->slab = slab;
}

//implements / extends the getDescription method from Confectionery
std::string Chocolate::getDescription(){
    std::string s = this->slab ? " slab" : " (not a slab)";
    this->setType(this->getType() + s);
    return Confectionery::getDescription();
}

//getters and setters
bool Chocolate::getSlab(){
    return this->slab;
}

void Chocolate::setSlab(bool slab){
    this->slab = slab;
}