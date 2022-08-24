#include "AeratedChocolate.h"
//constructor
AeratedChocolate::AeratedChocolate(std::string manufacturer, std::string type, int bubblespccm) : Confectionery(manufacturer, type, 0){
    this->bubblespccm = bubblespccm;
}
//implements / extends the getDescription method from Confectionery
std::string AeratedChocolate::getDescription(int id){
    return Confectionery::getDescription() + ": " + std::to_string(bubblespccm) + " bubbles per cubic cm";
}

//getters and setters
int AeratedChocolate::getBubblespccm(){
    return this->bubblespccm;
}

void AeratedChocolate::setBubblespccm(int bubblespccm){
    this->bubblespccm = bubblespccm;
}