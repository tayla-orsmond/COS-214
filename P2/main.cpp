#include "Game.h"
using namespace std;

int main(){
    srand(time(nullptr));
    Game * g = new Game();
    g->initialize();
    g->play();
    g->result();
    delete g;
    return 0;
}