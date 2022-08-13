#pragma once
#include "EnemyFactory.h"
#include "Jaguar.h"

class JaguarFactory: public EnemyFactory{
    public:
    JaguarFactory();
    ~JaguarFactory();
    Enemy* createEnemy(string, string);
};