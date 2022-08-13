#pragma once
#include "Enemy.h"
using namespace std;

class Gorilla: public Enemy{
    public:
        Gorilla(string name, int HP, int DMG, string ATK, string DEF);
        ~Gorilla();
    private:
        bool hitSquadMember(SquadMember *);
        bool getHit(SquadMember *);
        void celebrate();
        void die();
};