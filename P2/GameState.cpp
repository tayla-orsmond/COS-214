#include "GameState.h"
using namespace std;
//Tayla Orsmond u21467456
GameState::GameState(SquadMember * p,  
                vector<SquadMember *> c, 
                SquadStore * b, 
                vector<Enemy *> e, 
                int li, int d, int le, bool w, bool q){
    lives = li;
    diff = d;
    lvl = le;
    win = w;
    quit = q;
    player = p;
    clones = c;
    enemies = e;
    barracks = b;
}