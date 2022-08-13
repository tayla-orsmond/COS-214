#pragma once
#include <vector>
#include "SquadStore.h"
#include "SquadMember.h"
#include "Enemy.h"
using namespace std;
class Game;

class GameState{
    private:
    GameState(SquadMember *, 
                vector<SquadMember *>, 
                SquadStore *, 
                vector<Enemy *>, 
                int, int, int, bool, bool);
    
    friend class Game;
    int lives, diff, lvl;
    bool win, quit;
    SquadMember * player;
    vector<SquadMember *> clones;
    SquadStore * barracks;
    vector<Enemy *> enemies;
};