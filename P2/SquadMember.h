#pragma once
#include <string>
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
    private:
        void save();
        void reset();
        int HP;
        int DMG;
        string ATK;
        string DEF;
        string name;
};