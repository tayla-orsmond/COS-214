#include "AgileBattleState.h"
//constructor
AgileBattleState::AgileBattleState() : BattleState("agile"){
    std::cout << "\t\t\t\tAgileBattleState constructor" << std::endl;
}
//destructor
AgileBattleState::~AgileBattleState(){
    std::cout<<"\t\t\t\tAgileBattleState destructor"<<std::endl;
}
//handle function to handle "agile" battle state
int AgileBattleState::handle(std::string name, int dmg){
    dmg = (3 * dmg)/4 +1; 
    std::cout<< name <<" has selected an agile battle state, and is allowed two battle attacks in one turn and will deal "<<dmg<<" damage points"<<std::endl;
    return dmg;
}