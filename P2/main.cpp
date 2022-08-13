#include "Game.h"
using namespace std;

int main(){
    srand(time(nullptr));
    Game * g = new Game();
    g->initialize();
    g->play();
    bool r = g->result();
    if(r){
        g->restore();
    }
    delete g;
    return 0;
}