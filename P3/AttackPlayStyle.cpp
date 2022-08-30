#include "AttackPlayStyle.h"

//constructor
AttackPlayStyle::AttackPlayStyle(){
    std::cout << "AttackPlayStyle constructor" << std::endl;
}
//destructor
AttackPlayStyle::~AttackPlayStyle(){
    std::cout << "AttackPlayStyle destructor" << std::endl;
}

//attack
std::string AttackPlayStyle::attack(){
    return "is atttacking the opposing Pokemon";
}