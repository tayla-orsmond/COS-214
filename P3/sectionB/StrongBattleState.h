/* StrongBattleState class
 * Concrete state
 * Inherits from BattleState
 * This class implements handle() for StrongBattleState.
*/
#pragma once
#include "BattleState.h"

class StrongBattleState : public BattleState{
    public:
        StrongBattleState();
        ~StrongBattleState();
        int handle(std::string, int);//name, dmg
};