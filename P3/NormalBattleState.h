/* NormalBattleState class
 * Concrete state
 * Inherits from BattleState
 * This class implements handle() for NormalBattleState.
*/
#pragma once
#include "BattleState.h"
class NormalBattleState : public BattleState{
    public:
        NormalBattleState();
        ~NormalBattleState();
        int handle(std::string, int);//name, dmg
};