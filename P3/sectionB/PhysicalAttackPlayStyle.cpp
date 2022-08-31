#include "PhysicalAttackPlayStyle.h"

//constructor
PhysicalAttackPlayStyle::PhysicalAttackPlayStyle(): PlayStyle("physical"){
    std::cout << "\t\t\t\tPhysicalAttackPlayStyle constructor" << std::endl;
}
//destructor
PhysicalAttackPlayStyle::~PhysicalAttackPlayStyle(){
    std::cout << "\t\t\t\tPhysicalAttackPlayStyle destructor" << std::endl;
}

//attack
std::string PhysicalAttackPlayStyle::attack(){
    return "is using a physical ability to attack";
}
