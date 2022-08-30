#include "BattleState.h"
//constructor
BattleState::BattleState()
{
    battleStyle = "normal";
    std::cout << "\t\t\t\tBattleState constructor" << std::endl;
}
//parameterized constructor
BattleState::BattleState(std::string battleStyle)
{
    this->battleStyle = battleStyle;
    std::cout << "\t\t\t\tBattleState constructor" << std::endl;
}
//destructor
BattleState::~BattleState()
{
    std::cout<<"\t\t\t\tBattleState destructor"<<std::endl;
}
//getter
std::string BattleState::getBattleStyle()
{
    return battleStyle;
}