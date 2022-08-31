/* The Pokemon class
 * This class is used to create a Pokemon.
    * It has a name, DMG, and HP.
*/
#pragma once
#include <string>
#include <iostream>
#include "BattleState.h"
#include "NormalBattleState.h"
#include "StrongBattleState.h"
#include "AgileBattleState.h"
#include "PlayStyle.h"

class Pokemon{
    public:
        Pokemon(BattleState * state, PlayStyle * style);
        Pokemon(std::string name, int dmg, int hp, PlayStyle * style, BattleState * state);
        ~Pokemon();
        int SelectBattleState();//returns dmg, calls handle() from BattleState
        int attack();//returns dmg, outputs playstyle and attack (+ new dmg)
        //getters and setters
        int getDmg();
        int getHP();
        void takeDmg(int dmg);
        std::string getName();
        PlayStyle * getStyle();
        void setStyle(PlayStyle * style);
        BattleState * getState();
    private:
        void setState(BattleState * state);
        std::string name;
        int dmg;
        int hp;
        BattleState * state;
        PlayStyle * style;
};

