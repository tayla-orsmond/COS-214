#include <iostream>
#include <ctime>
#include "SquadMember.h"
using namespace std;

SquadMember::SquadMember(string name){
    const int SIZE = 6;
    string atks[SIZE] = {"A Magic Girl wand", "A coffee mug", "A big stick", "Gun", "The power of gaslighting", "A baseball bat"};
    string defs[SIZE] = {"a COS214 tutor", "a shield", "simply saying 'no'", "a rock", "a large friend", "someone's cat"};
    this->name = name;
    this->HP = rand() % 11 + 1;
    this->DMG = rand() % 11 + 1;
    this->ATK = atks[rand() % SIZE];
    this->DEF = defs[rand() % SIZE];
    cout<<"[[Squad Member "<< name<<" created.]]\n";
}
SquadMember::SquadMember(string name, int hp, int dmg, string atk, string def){
    this->name = name;
    this->HP = hp;
    this->DMG = dmg;
    this->ATK = atk;
    this->DEF = def;
}
SquadMember::~SquadMember(){
    cout<<"[[Squad Member destroyed.]]\n";
}
int SquadMember::takeDMG(int dmg){
    this->HP -= dmg;
    return this->HP;
}
int SquadMember::getDMG(){
    return this->DMG;
}
void SquadMember::setDMG(int dmg){
    this->DMG = dmg;
}
int SquadMember::getHP(){
    return this->HP;
}
void SquadMember::setHP(int hp){
    this->HP = hp;
}
string SquadMember::getName(){
    return this->name;
}
string SquadMember::getATK(){
    return this->ATK;
}
string SquadMember::getDEF(){
    return this->DEF;
}
void SquadMember::die(){
    this->HP = 0;
    this->DMG = 0;
    cout<<"[[Squad Member "<<this->name<<" has died!]]\n";
}
SquadMember * SquadMember::clone(){
    return new SquadMember("A Cooler Clone of "+ this->name, this->HP, this->DMG, this->ATK, this->DEF);
}
SquadMemento * SquadMember::save(int move){
    return new SquadMemento(this->HP, this->DMG, this->ATK, this->DEF, move);
}
void SquadMember::restore(SquadMemento * save){
    this->ATK = save->atk;
    this->DEF = save->def;
    this->HP = save->hp;
    this->DMG = save->dmg;
}