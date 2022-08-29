#include "Cadbury.h"
//constructor
Cadbury::Cadbury(){
    std::cout<<"Cadbury Factory created!\n";
}
//destructor
Cadbury::~Cadbury(){
    std::cout<<"Cadbury Factory destroyed.\n";

}
//create chocolate
Confectionery * Cadbury::createChocolate(bool slab){
    return new DairyMilk(slab);
}
//create aerated chocolate
Confectionery * Cadbury::createAeratedChocolate(int bubblespccm){
    return new DairyMilkBubbly(bubblespccm);
}