/* The BattleState class
 * Abstract class 
 * This class implements the functionality to create a BattleState.
 * It has a battleStyle and interacts with Pokemon.
 */
#pragma once
#include <string>
#include <iostream>
// #include "Pokemon.h" 
//would typically have this, but battlestate doesn't need to know about pokemon in this implementation (which removes the circular dependency).

class BattleState{
    public:
        BattleState();
        BattleState(std::string);//battleStyle
        virtual ~BattleState();
        virtual int handle(std::string, int) = 0;//name, dmg
        //abstract function that returns amended dmg based on battle style
    protected:
        std::string battleStyle;// "normal" or "agile" or "strong"
};