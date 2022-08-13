#pragma once
#include "GameState.h"
using namespace std;
//Tayla Orsmond u21467456

class GameStore{
    public:
    GameStore();
    ~GameStore();
    void store(GameState *);
    GameState * restore();
    void save();
    vector<GameState *> load();
    void clear();
    private:
    vector<GameState *> saves;
};