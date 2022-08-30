/* AgileBattleState class
 * Concrete state
 * Inherits from BattleState
 * This class implements handle() for AgileBattleState.
*/
#pragma once
#include "BattleState.h"

class AgileBattleState : public BattleState{
    public:
        AgileBattleState();
        ~AgileBattleState();
        int handle(Pokemon *, std::string);//context, strategy
};