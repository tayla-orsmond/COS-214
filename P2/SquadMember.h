#pragma once
#include <string>
#include "SquadMemento.h"
using namespace std;

class SquadMember{
    public:
        SquadMember(){};
        SquadMember(string);
        SquadMember(string, int, int, string, string);
        ~SquadMember();
        int takeDMG(int dmg);
        int getDMG();
        void setDMG(int dmg);
        int getHP();
        void setHP(int hp);
        string getName();
        string getATK();
        string getDEF();
        void die();
        SquadMember * clone();
        SquadMemento * save(int);
        void restore(SquadMemento * );
    private:
        int HP;
        int DMG;
        string ATK;
        string DEF;
        string name;
};