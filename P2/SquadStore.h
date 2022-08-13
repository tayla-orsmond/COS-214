#pragma once
#include <vector>
#include "SquadMemento.h"
using namespace std;
//Tayla Orsmond u21467456
class SquadStore{
    public:
    SquadStore();
    ~SquadStore();
    void store(SquadMemento *);
    SquadMemento * restore();
    void clear();
    vector<SquadMemento*> load();
    private:
    vector<SquadMemento*> squad;
};