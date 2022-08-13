#pragma once
#include "EnemyFactory.h"
#include "Cannibal.h"

class CannibalFactory: public EnemyFactory{
    public:
    CannibalFactory();
    ~CannibalFactory();
    Enemy* createEnemy(string, string);
};