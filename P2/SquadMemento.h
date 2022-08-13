#pragma once
#include <string>
using namespace std;
//Tayla Orsmond u21467456
class SquadMember;

class SquadMemento{
    private:
    SquadMemento(int, int, string, string, int);
    int hp, dmg, lastMove;
    string atk, def;
    friend class SquadMember;
};