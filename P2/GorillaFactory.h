#pragma once
#include "EnemyFactory.h"
#include "Gorilla.h"

class GorillaFactory: public EnemyFactory{
    public:
    GorillaFactory();
    ~GorillaFactory();
    Enemy* createEnemy(string, string);
};