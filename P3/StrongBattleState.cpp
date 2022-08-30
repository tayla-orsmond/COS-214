#include "StrongBattleState.h"
//constructor
StrongBattleState::StrongBattleState() : BattleState("strong"){
    std::cout << "\t\t\t\tStrongBattleState constructor" << std::endl;
}
//destructor
StrongBattleState::~StrongBattleState(){
    std::cout<<"\t\t\t\tStrongBattleState destructor"<<std::endl;
}
//handle function to handle "strong" battle state
int StrongBattleState::handle(Pokemon * p, std::string strategy){
    //handle the damage and battle
    int dmg = p->getDmg() * 2;
    std::cout<< p->getName() <<" has selected a strong battle state, and will inflict "<<dmg<<" damage points on the next battle attack but misses the following attack turn"<<std::endl;
    //switch state based on playstyle
    if(strategy == "attack"){
        p->setState(new NormalBattleState());
    }
    if(strategy == "run"){
        p->setState(new AgileBattleState());
    }
    if(strategy == "physical"){
        if(rand() % 5 == 0){
            p->setState(new NormalBattleState());
        }
        //strategy == "physical" may keep this state
    }
    return dmg;
}