#pragma once
#include "EnemyFactory.h"
#include "Snake.h"

class SnakeFactory: public EnemyFactory{
    public:
    SnakeFactory();
    ~SnakeFactory();
    Enemy* createEnemy(string, string);
};