#include "AeratedChocolate.h"
//constructor
AeratedChocolate::AeratedChocolate(std::string manufacturer, double price, int bubblespccm) : Confectionery(manufacturer, "Aerated chocolate", price){
    this->bubblespccm = bubblespccm;
}
//destructor
AeratedChocolate::~AeratedChocolate(){
    std::cout<<"Aerated chocolate eaten.\n";
}
//implements / extends the getDescription method from Confectionery
std::string AeratedChocolate::getDescription(){
    return Confectionery::getDescription() + ": " + std::to_string(this->bubblespccm) + " bubbles per cubic cm";
}

//getters and setters
int AeratedChocolate::getBubblespccm(){
    return this->bubblespccm;
}

void AeratedChocolate::setBubblespccm(int bubblespccm){
    this->bubblespccm = bubblespccm;
}