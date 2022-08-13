#include "GameStore.h"
using namespace std;

GameStore::GameStore(){
    //this->clear();
}
void GameStore::store(GameState * s){
    this->saves.push_back(s);
}
GameState * GameStore::restore(){
    if(this->saves.size() == 0){return nullptr;}
    GameState * s = this->saves.back();
    this->saves.pop_back();
    return s;
}
void GameStore::clear(){
    vector<GameState *>::iterator i;
    for (i = this->saves.begin(); i != this->saves.end(); i++)
    {
        GameState * s = this->saves.back();
        this->saves.pop_back();
        delete s;
    }
    
}