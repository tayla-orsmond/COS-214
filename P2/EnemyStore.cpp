#include "EnemyStore.h"
//Tayla Orsmond u21467456

void EnemyStore::hide(EnemyMemento * e){
    finalBoss.push_back(e);
}
EnemyMemento * EnemyStore::retrieve(){
    EnemyMemento * e = finalBoss.back();
    finalBoss.pop_back();
    return e;
}