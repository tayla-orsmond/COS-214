#include <iostream>
#include "Snake.h"

Snake::Snake(string name, int HP, int DMG, string ATK, string DEF): Enemy(name, HP, DMG, ATK, DEF){

}
Snake::~Snake(){

}
bool Snake::hitSquadMember(SquadMember * target){
    cout<<this->name<<" the snake wraps around "<<target->getName()<<" and uses "<<this->ATK<<endl;
    target->takeDMG(this->DMG);//hit SquadMember
    if(target->getHP() <= 0) return true;
    return false;
}
bool Snake::getHit(SquadMember * attacker){
    cout<<this->name<<" slithers rapidly searching for safety and employs "<<this->DEF<<endl;
    if(attacker->getHP() > 0){
        this->HP -= attacker->getDMG();//get hit by SquadMember
    }
    if(this->HP <= 0) return true;
    return false;
}   
void Snake::celebrate(){
    cout<<this->name<<" celebrates. You tried strongly till the end.\n";
}
void Snake::die(){
    this->HP = 0;
    this->DMG = 0;
    cout<<this->name<<" hisses and curls up as they are defeated.\n";
}
