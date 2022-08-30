#include "AgileBattleState.h"
//constructor
AgileBattleState::AgileBattleState() : BattleState("agile"){

}
//destructor
AgileBattleState::~AgileBattleState(){
    std::cout<<"AgileBattleState destructor"<<std::endl;
}
//handle function to handle "agile" battle state
int AgileBattleState::handle(std::string name, int dmg){
    dmg *= 3/4;
    std::cout<<name <<" has selected an agile battle state, and is allowed two battle attacks in one turn and will deal "<<dmg<<" damage points"<<std::endl;
    return dmg;
}