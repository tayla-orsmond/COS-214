#include "PlayStyle.h"
//constructor
PlayStyle::PlayStyle(std::string style){
    this->style = style;
    std::cout << "\t\t\t\tPlayStyle constructor" << std::endl;
}
//destructor
PlayStyle::~PlayStyle(){
    std::cout << "\t\t\t\tPlayStyle destructor" << std::endl;
}
//getters and setters
std::string PlayStyle::getStyle(){
    return this->style;
}