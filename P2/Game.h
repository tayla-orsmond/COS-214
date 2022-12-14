#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include "SquadMember.h"
#include "SquadStore.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "EnemyStore.h"
#include "Cannibal.h"
#include "CannibalFactory.h"
#include "Gorilla.h"
#include "GorillaFactory.h"
#include "Jaguar.h"
#include "JaguarFactory.h"
#include "Snake.h"
#include "SnakeFactory.h"
using namespace std;

class Game{
    public:
    Game();
    ~Game();
    void initialize();
    void play();
    bool result();
    void restore();

    private:
    const string GAMENAME = "Adventure Island";
    int lives, diff, lvl;
    bool win, quit;
    SquadMember * player;
    vector<SquadMember *> clones;
    SquadStore * barracks;
    vector<Enemy *> enemies;
    EnemyStore * finalBoss;
    static const int SIZE = 7;
    string atks[SIZE] = {"a bow and arrow", "a vicious scream", "another coffee mug", "a boulder", "a plakkie", "sparkles!!!", "a COS semester test"};
    string defs[SIZE] = {"an uno reverse card", "a really big umbrella", "giving you a stern talking to", "a backhand", "a Barricade", "a plastic bubble that 'looks like a disco ball'"};
};