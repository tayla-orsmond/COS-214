#include "StrongBattleState.h"
//constructor
StrongBattleState::StrongBattleState() : BattleState("strong"){

}
//destructor
StrongBattleState::~StrongBattleState(){
    std::cout<<"StrongBattleState destructor"<<std::endl;
}
//handle function to handle "strong" battle state
int StrongBattleState::handle(std::string name, int dmg){
    dmg *= 2;
    std::cout<<name <<" has selected a strong battle state, and will inflict "<<dmg<<" damage points on the next battle attack but misses the following attack turn"<<std::endl;
    return dmg;
}