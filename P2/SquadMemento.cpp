#include "SquadMemento.h"
SquadMemento::SquadMemento(int hp, int dmg, string atk, string def, int m){
    this->hp = hp;
    this->dmg = dmg;
    this->atk = atk;
    this->def = def;
    this->lastMove = m;
}