#include "Chocolate.h"
//constructor
Chocolate::Chocolate(std::string manufacturer, double price, bool slab) : Confectionery(manufacturer, "Chocolate", price){
    this->slab = slab;
    std::string s = this->slab ? " slab" : " bar (not a slab)";
    this->setType(this->getType() + s);
}
//destructor
Chocolate::~Chocolate(){
    std::cout<<"Chocolate eaten.\n";
}
//implements / extends the getDescription method from Confectionery
std::string Chocolate::getDescription(){
    return Confectionery::getDescription();
}

//getters and setters
bool Chocolate::getSlab(){
    return this->slab;
}

void Chocolate::setSlab(bool slab){
    this->slab = slab;
}