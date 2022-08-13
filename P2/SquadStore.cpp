#include "SquadStore.h"
void SquadStore::store(SquadMemento * player){
    this->squad.push_back(player);
}
SquadMemento * SquadStore::restore(){
    if(this->squad.size() == 0) return nullptr;
    SquadMemento * m = this->squad.back();
    this->squad.pop_back();
    return m;
}
void SquadStore::clear(){
    vector<SquadMemento *>::iterator i;
    for(i = this->squad.begin(); i != this->squad.end(); i++){
        SquadMemento * m = this->squad.back();
        this->squad.pop_back();
        delete m;
    }
    this->squad.clear();
}
vector<SquadMemento*> SquadStore::load(){
    return this->squad;
}
int SquadStore::size(){
    return this->squad.size();
}
