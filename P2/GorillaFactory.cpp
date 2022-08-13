#include <ctime>
#include "GorillaFactory.h"
GorillaFactory::GorillaFactory(){

}
GorillaFactory::~GorillaFactory(){

}
Enemy* GorillaFactory::createEnemy(string a, string d){
    int hp = rand() % 12 + 4;
    int dmg = 1;
    string atk = a;
    string def = d;
    string name = getName();
    return new Gorilla(name, hp, dmg, atk, def);
}