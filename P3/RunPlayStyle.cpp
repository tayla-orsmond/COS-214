#include "RunPlayStyle.h"
//constructor
RunPlayStyle::RunPlayStyle(): PlayStyle("run"){
    std::cout << "\t\t\t\tRunPlayStyle constructor" << std::endl;
}
//destructor
RunPlayStyle::~RunPlayStyle(){
    std::cout << "\t\t\t\tRunPlayStyle destructor" << std::endl;
}
//attack
std::string RunPlayStyle::attack(){
    return "decides life is better than death and leaves the battle";
}
