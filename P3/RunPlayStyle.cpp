#include "RunPlayStyle.h"
//constructor
RunPlayStyle::RunPlayStyle(){
    std::cout << "RunPlayStyle constructor" << std::endl;
}
//destructor
RunPlayStyle::~RunPlayStyle(){
    std::cout << "RunPlayStyle destructor" << std::endl;
}
//attack
std::string RunPlayStyle::attack(){
    return "decides life is better than death and leaves the battle";
}
