#include "AttackPlayStyle.h"

//constructor
AttackPlayStyle::AttackPlayStyle(): PlayStyle("attack"){
    std::cout << "\t\t\t\tAttackPlayStyle constructor" << std::endl;
}
//destructor
AttackPlayStyle::~AttackPlayStyle(){
    std::cout << "\t\t\t\tAttackPlayStyle destructor" << std::endl;
}

//attack
std::string AttackPlayStyle::attack(){
    return "is atttacking the opposing Pokemon";
}