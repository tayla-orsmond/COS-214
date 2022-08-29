#include "Chocolate.h"
//constructor
Chocolate::Chocolate(std::string manufacturer, double price, bool slab) : Confectionery(manufacturer, "Chocolate", price){
    this->slab = slab;
}

//implements / extends the getDescription method from Confectionery
std::string Chocolate::getDescription(bool slab){
    if(slab){
        return Confectionery::getDescription() + " chocolate slab.";
    }
    else{
        return Confectionery::getDescription() + " chocolate no slab.";
    }
}

//getters and setters
bool Chocolate::getSlab(){
    return this->slab;
}

void Chocolate::setSlab(bool slab){
    this->slab = slab;
}