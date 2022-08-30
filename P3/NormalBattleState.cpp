#include "NormalBattleState.h"
//constructor
NormalBattleState::NormalBattleState(): BattleState("normal"){
    std::cout<<"\t\t\t\tNormalBattleState constructor"<<std::endl;
}
//destructor
NormalBattleState::~NormalBattleState(){
    std::cout<<"\t\t\t\tNormalBattleState destructor"<<std::endl;
}
//handle function to handle "normal" battle state
int NormalBattleState::handle(Pokemon * p, std::string strategy){
    int dmg = p->getDmg();
    std::cout<<p->getName() <<" has no special battle state, normal battle attack will deal "<<dmg<<" damage points"<<std::endl;
    if(strategy == "attack"){
        if(rand() % 3 == 0){
            p->setState(new StrongBattleState());
        }
        //strategy == "attack" may keep this state
    }
    if(strategy == "run"){
        p->setState(new AgileBattleState());
    }
    if(strategy == "physical"){
        p->setState(new StrongBattleState());
    }
    return dmg;
}