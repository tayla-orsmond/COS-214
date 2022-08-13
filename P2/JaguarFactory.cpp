#include "JaguarFactory.h"
JaguarFactory::JaguarFactory(){

}
JaguarFactory::~JaguarFactory(){

}
Enemy* JaguarFactory::createEnemy(string a, string d){
    int hp = generate(10,13);
    int dmg = 4;
    string atk = a;
    string def = d;
    string name = getName();
    return new Jaguar(name, hp, dmg, atk, def);
}