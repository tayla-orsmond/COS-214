#pragma once
#include "Enemy.h"
using namespace std;

class Jaguar: public Enemy{
    public:
        Jaguar(string name, int HP, int DMG, string ATK, string DEF);
        ~Jaguar();
    private:
        bool hitSquadMember(SquadMember *);
        bool getHit(SquadMember *);
        void celebrate();
        void die();
};