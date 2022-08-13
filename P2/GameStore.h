#pragma once
#include <vector>
#include "GameState.h"
using namespace std;
//Tayla Orsmond u21467456

class GameStore{
    public:
    GameStore();
    void store(GameState *);
    GameState * restore();
    void clear();
    private:
    vector<GameState *> saves;
};