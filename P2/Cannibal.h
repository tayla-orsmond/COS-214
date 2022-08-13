#pragma once 
#include "Enemy.h"
using namespace std;

class Cannibal: public Enemy{
    public:
        Cannibal(string name, int HP, int DMG, string ATK, string DEF);
        ~Cannibal();
    private:
        bool hitSquadMember(SquadMember *);
        bool getHit(SquadMember *);
        void celebrate();
        void die();
};