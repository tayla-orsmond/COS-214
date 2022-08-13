#include <iostream>
#include "Jaguar.h"

Jaguar::Jaguar(string name, int HP, int DMG, string ATK, string DEF): Enemy(name, HP, DMG, ATK, DEF){

}
Jaguar::~Jaguar(){

}
bool Jaguar::hitSquadMember(SquadMember * target){
    cout<<this->name<<" the jaguar leaps toward "<<target->getName()<<" and delivers a forceful blow with "<<this->ATK<<endl;
    target->takeDMG(this->DMG);//hit SquadMember
    if(target->getHP() <= 0) return true;
    return false;
}
bool Jaguar::getHit(SquadMember * attacker){
    cout<<this->name<<" growls in pain as they are maimed. The jaguar turns around and delivers "<<this->DEF<<" against "<< attacker->getName()<<endl;
    if(attacker->getHP() > 0){
        this->HP -= attacker->getDMG();//get hit by SquadMember
    }
    if(this->HP <= 0) return true;
    return false;
}   
void Jaguar::celebrate(){
    cout<<this->name<<" celebrates. You should have fought harder soldier.\n";
}
void Jaguar::die(){
    this->HP = 0;
    this->DMG = 0;
    cout<<this->name<<" gives one last growl before falling over.\n";
}