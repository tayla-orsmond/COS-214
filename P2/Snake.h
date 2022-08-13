#pragma once
#include "Enemy.h"
using namespace std;

class Snake: public Enemy{
    public:
        Snake(string name, int HP, int DMG, string ATK, string DEF);
        ~Snake();
    private:
        bool hitSquadMember(SquadMember *);
        bool getHit(SquadMember *);
        void celebrate();
        void die();
};