#include "BattleState.h"
//constructor
BattleState::BattleState()
{
    battleStyle = "normal";
}
//parameterized constructor
BattleState::BattleState(std::string battleStyle)
{
    this->battleStyle = battleStyle;
}
//destructor
BattleState::~BattleState()
{
    std::cout<<"BattleState destructor"<<std::endl;
}