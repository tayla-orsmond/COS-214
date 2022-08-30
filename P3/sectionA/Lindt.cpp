#include "Lindt.h"
//constructor
Lindt::Lindt(){
    std::cout<<"Lindt Factory created!\n";
}
//destructor
Lindt::~Lindt(){
    std::cout<<"Lindt Factory destroyed.\n";
}
//create chocolate
Confectionery * Lindt::createChocolate(bool slab){
    return new Lindor(slab);
}
//create aerated chocolate
Confectionery * Lindt::createAeratedChocolate(int bubblespccm){
    return nullptr;
}