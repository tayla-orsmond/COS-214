#include <iostream>
#include "Enemy.h"
using namespace std;

Enemy::Enemy(string name, int HP, int DMG, string ATK, string DEF){
    this->HP = HP;
    this->DMG = DMG;
    this->ATK = ATK;
    this->DEF = DEF;
    this->name = name;
    cout<<"[[Enemy "<<this->name<<" Created!]]\n";
}
Enemy::~Enemy(){
    cout<<"[[Enemy Destroyed!]]\n";
}
void Enemy::attack(SquadMember * target){
    while(target->getHP() > 0 && this->HP > 0){
        if(hitSquadMember(target)){
            target->die();//target dies
            this->celebrate();
        }
        else if(getHit(target)){
            this->die();
        }
    }
}
string Enemy::getName(){
    return this->name;
}
string Enemy::getATK(){
    return this->ATK;
}
string Enemy::getDEF(){
    return this->DEF;
}
int Enemy::getHP(){
    return this->HP;
}
int Enemy::getDMG(){
    return this->DMG;
}