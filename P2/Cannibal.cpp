#include <iostream>
#include "Cannibal.h"

Cannibal::Cannibal(string name, int HP, int DMG, string ATK, string DEF): Enemy(name, HP, DMG, ATK, DEF){

}
Cannibal::~Cannibal(){

}
bool Cannibal::hitSquadMember(SquadMember * target){
    cout<<this->name<<" the cannibal rushes towards "<<target->getName()<<" with "<<this->ATK<<endl;
    target->takeDMG(this->DMG);//hit SquadMember
    if(target->getHP() <= 0) return true;
    return false;
}
bool Cannibal::getHit(SquadMember * attacker){
    cout<<this->name<<" is hit! The other villagers come running, deploying "<<this->DEF<<endl;
    if(attacker->getHP() > 0){
        this->HP -= attacker->getDMG();//get hit by SquadMember
    }
    if(this->HP <= 0) return true;
    return false;
}   
void Cannibal::celebrate(){
    cout<<this->name<<" celebrates and shakes their "<<this->ATK<<" at the player's remains.\n";
}
void Cannibal::die(){
    this->HP = 0;
    this->DMG = 0;
    cout<<this->name<<" screams with their last breath, 'I am your father'.\n";
}