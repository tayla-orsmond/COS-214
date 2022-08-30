#include "PhysicalAttackPlayStyle.h"

//constructor
PhysicalAttackPlayStyle::PhysicalAttackPlayStyle(){
    std::cout << "PhysicalAttackPlayStyle constructor" << std::endl;
}
//destructor
PhysicalAttackPlayStyle::~PhysicalAttackPlayStyle(){
    std::cout << "PhysicalAttackPlayStyle destructor" << std::endl;
}

//attack
std::string PhysicalAttackPlayStyle::attack(){
    return "is using physical ability to attack";
}
