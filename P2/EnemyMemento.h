#pragma once
#include <string>
using namespace std;
//Tayla Orsmond u21467456

class Enemy;

class EnemyMemento{
    private:
    EnemyMemento(int, int, string, string, string);
    void supersize();
    int hp, dmg;
    string atk, def;
    friend class Enemy;
};