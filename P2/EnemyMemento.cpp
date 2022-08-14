#include "EnemyMemento.h"
#include<iostream>
using namespace std;
//Tayla Orsmond u21467456

EnemyMemento::EnemyMemento(int hp, int dmg, string atk, string def, string name){
    this->hp = hp;
    this->dmg = dmg;
    this->atk = atk;
    this->def = def;
    this->supersize();
}
void EnemyMemento::supersize(){
    this->hp *= 5;
    this->dmg *= 5;
}