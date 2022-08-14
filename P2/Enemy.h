#pragma once 
#include <string>
#include "SquadMember.h"
#include "EnemyMemento.h"
using namespace std;

//Tayla Orsmond u21467456

class Enemy{
    public:
        Enemy(string name, int HP, int DMG, string ATK, string DEF);
        virtual ~Enemy();
        void attack(SquadMember *);//Template Function
        virtual bool hitSquadMember(SquadMember *) = 0;
        virtual bool getHit(SquadMember *) = 0;
        virtual void celebrate() = 0;
        virtual void die() = 0;
        string getName();
        string getATK();
        string getDEF();
        int getHP();
        int getDMG();
        EnemyMemento * save();
        void restore(EnemyMemento *);
    protected:
        int HP;
        int DMG;
        string ATK;
        string DEF;
        string name;
};
