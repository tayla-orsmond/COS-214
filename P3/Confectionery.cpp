#include "Confectionery.h"
//constructor
Confectionery::Confectionery(std::string manufacturer, std::string type, double){
    this->manufacturer = manufacturer;
    this->type = type;
    this->price = price;
}

Confectionery::~Confectionery(){
    std::cout << "Confectionery destroyed" << std::endl;
}
//return summary of parameters
std::string Confectionery::getDescription(){
    return manufacturer + ": " + type + ": " + std::to_string(price) + ", ID:  " + std::to_string(id);
}

//getters and setters
double Confectionery::getPrice(){
    return price;
}

void Confectionery::setPrice(double price){
    this->price = price;
}

std::string Confectionery::getManufacturer(){
    return manufacturer;
}

void Confectionery::setManufacturer(std::string manufacturer){
    this->manufacturer = manufacturer;
}

std::string Confectionery::getType(){
    return type;
}

void Confectionery::setType(std::string type){
    this->type = type;
}

int Confectionery::getId(){
    return id;
}

void Confectionery::setId(int id){
    this->id = id;
}