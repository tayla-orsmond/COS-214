#include <ctime>
#include "CannibalFactory.h"
CannibalFactory::CannibalFactory(){

}
CannibalFactory::~CannibalFactory(){

}
Enemy* CannibalFactory::createEnemy(string a, string d){
    int hp = rand() % 30 + 8;
    int dmg = 6;
    string atk = a;
    string def = d;
    string name = getName();
    return new Cannibal(name, hp, dmg, atk, def);
}