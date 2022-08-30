#include "Nestle.h"
//constructor
Nestle::Nestle(){
    std::cout<<"Nestle Factory created!\n";
}
//destructor
Nestle::~Nestle(){
    std::cout<<"Nestle Factory destroyed.\n";
}
//create chocolate
Confectionery * Nestle::createChocolate(bool slab){
    return new MilkyBar(slab);
}
//create aerated chocolate
Confectionery * Nestle::createAeratedChocolate(int bubblespccm){
    return new Aero(bubblespccm);
}