#include "AgileBattleState.h"
//constructor
AgileBattleState::AgileBattleState() : BattleState("agile"){
    std::cout << "\t\t\t\tAgileBattleState constructor" << std::endl;
}
//destructor
AgileBattleState::~AgileBattleState(){
    std::cout<<"\t\t\t\tAgileBattleState destructor"<<std::endl;
}
//handle function to handle "agile" battle state
int AgileBattleState::handle(Pokemon * p, std::string strategy){
    int dmg = p->getDmg() * 3/4; 
    std::cout<<p->getName() <<" has selected an agile battle state, and is allowed two battle attacks in one turn and will deal "<<dmg<<" damage points"<<std::endl;
    if(strategy == "attack"){
        p->setState(new NormalBattleState());
    }
    if(strategy == "run"){
        if(rand() % 4 == 0){
            p->setState(new NormalBattleState());
        }
        //strategy == "run" may keep this state
    }
    if(strategy == "physical"){
        p->setState(new StrongBattleState());
    }
    return dmg;
}