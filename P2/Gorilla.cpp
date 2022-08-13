#include <iostream>
#include "Gorilla.h"

Gorilla::Gorilla(string name, int HP, int DMG, string ATK, string DEF): Enemy(name, HP, DMG, ATK, DEF){

}
Gorilla::~Gorilla(){

}
bool Gorilla::hitSquadMember(SquadMember * target){
    cout<<this->name<<" the gorilla slams their fists on the ground, growls and hits "<<target->getName()<<" with "<<this->ATK<<endl;
    target->takeDMG(this->DMG);//hit SquadMember
    if(target->getHP() <= 0) return true;
    return false;
}
bool Gorilla::getHit(SquadMember * attacker){
    cout<<this->name<<" roars and hits their chest in anger. The gorilla employs "<<this->DEF<<endl;
    if(attacker->getHP() > 0){
        this->HP -= attacker->getDMG();//get hit by SquadMember
    }
    if(this->HP <= 0) return true;
    return false;
}   
void Gorilla::celebrate(){
    cout<<this->name<<" celebrates. You tried in vain to save yourself.\n";
}
void Gorilla::die(){
    this->HP = 0;
    this->DMG = 0;
    cout<<"The earth shakes as Gorilla "<<this->name<<" falls to the ground.\n";
}