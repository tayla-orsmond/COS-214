#pragma once
#include "SquadMember.h"
using namespace std;
//Tayla Orsmond u21467456
class SquadMemento{
    private:
    SquadMemento(SquadMember *);
    ~SquadMemento();
    int lastMove;
    SquadMember * member;
    friend class SquadMember;
};