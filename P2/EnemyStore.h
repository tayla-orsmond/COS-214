#pragma once
#include <vector>
#include "EnemyMemento.h"
using namespace std;
//Tayla Orsmond u21467456

class EnemyStore{
    public:
    void hide(EnemyMemento *);
    EnemyMemento * retrieve();
    private:
    vector<EnemyMemento *> finalBoss;
};