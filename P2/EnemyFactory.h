#pragma once
#include <string>
#include "Enemy.h"
using namespace std;
//Tayla Orsmond u21467456

class EnemyFactory{
    public:
        EnemyFactory();
        virtual ~EnemyFactory();
        virtual Enemy* createEnemy(string, string) = 0;
    protected:
        string getName();
        int generate(int, int);
};