#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "SquadMember.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "Cannibal.h"
#include "CannibalFactory.h"
#include "Gorilla.h"
#include "GorillaFactory.h"
#include "Jaguar.h"
#include "JaguarFactory.h"
#include "Snake.h"
#include "SnakeFactory.h"
#include "GameState.h"
using namespace std;

class Game{
    public:
    Game(string playername, int difficulty);
    bool playGame();
    void printResult();
    void saveGame();
    GameState * restoreGame();
    void saveMove();

    private:
    const string GAMENAME = "Adventure Island";
    SquadMember * player;
    int lives, diff;
    bool win;
    vector<Enemy *> enemies;
    vector<int> moves;
    static const int SIZE = 7;
    string atks[SIZE] = {"a bow and arrow", "a vicious scream", "another coffee mug", "a boulder", "a plakkie", "sparkles!!!", "a COS semester test"};
    string defs[SIZE] = {"an uno reverse card", "a really big umbrella", "giving you a stern talking to", "a backhand", "a Barricade", "a plastic bubble that 'looks like a disco ball'"};
};