#include "SnakeFactory.h"
SnakeFactory::SnakeFactory(){

}
SnakeFactory::~SnakeFactory(){

}
Enemy* SnakeFactory::createEnemy(string a, string d){
    int hp = generate(6,1);
    int dmg = 2;
    string atk = a;
    string def = d;
    string name = getName();
    return new Snake(name, hp, dmg, atk, def);
}