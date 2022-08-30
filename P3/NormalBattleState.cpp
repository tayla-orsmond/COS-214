#include "NormalBattleState.h"
//constructor
NormalBattleState::NormalBattleState(): BattleState("normal"){

}
//destructor
NormalBattleState::~NormalBattleState(){
    std::cout<<"NormalBattleState destructor"<<std::endl;
}
//handle function to handle "normal" battle state
int NormalBattleState::handle(std::string name, int dmg){
    std::cout<<name <<" has no special battle state, normal battle attack will deal "<<dmg<<" damage points"<<std::endl;
    return dmg;
}