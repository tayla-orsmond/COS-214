#include "Pokemon.h"
//constructor
Pokemon::Pokemon(BattleState * state, PlayStyle * style)
{
    const std::string NAMES [] = {"Pikachu", "Bulbasaur", "Charmander", "Squirtle", "Pidgey", "Rattata", "Raticate", "Magikarp", "Gyarados", "Lapras", "Vaporeon", "Jolteon", "Flareon", "Eevee", "Snorlax"};
    this->name = NAMES[rand() % 15 +1];
    this->dmg = (rand() % 30) + 1;
    this->hp = (rand() % 100) + 1;
    this->style = style;
    this->state = state;
    std::cout << "\t\t\t\t" << this->name << " has been born" << std::endl;
}
//parameterized constructor
Pokemon::Pokemon(std::string name, int dmg, int hp, PlayStyle * style, BattleState * state)
{
    this->name = name;
    this->dmg = dmg;
    this->hp = hp;
    this->style = style;
    this->state = state;
    std::cout << "\t\t\t\t" << this->name << " has been born" << std::endl;
}
//destructor
Pokemon::~Pokemon()
{
    std::cout << "\t\t\t\tPokemon has died!" << std::endl;
}
//select battle state function
int Pokemon::SelectBattleState(){
    //handle battle
    int res = this->state->handle(this->name, this->dmg);
    //switch state based on playstyle
    if(this->style->getStyle() == "attack"){
        if(this->state->getBattleStyle() != "normal")
            this->setState(new NormalBattleState());
        else if(rand() % 5 == 0){
            this->setState(new StrongBattleState());
        }
    }
    if(this->style->getStyle() == "run"){
        if(this->state->getBattleStyle() != "agile")
            this->setState(new AgileBattleState());
        else if(rand() % 2 == 0){
            this->setState(new NormalBattleState());
        }
    }
    if(this->style->getStyle() == "physical"){
        if(this->state->getBattleStyle() != "strong")
            this->setState(new StrongBattleState());
        else if(rand() % 3 == 0){
            this->setState(new NormalBattleState());
        }
    }
    return res;
}
//attack function
int Pokemon::attack(){
    if(this->hp <= 0){
        std::cout<< this->name << " has fainted and cannot attack!"<<std::endl;
        return 0;
    }
    std::cout << this->name << " " << this->style->attack() << std::endl;
    this->dmg = SelectBattleState();
    return this->dmg;
}
//getters and setters
int Pokemon::getDmg(){
    return this->dmg;
}
int Pokemon::getHP(){
    return this->hp;
}
void Pokemon::takeDmg(int dmg){
    this->hp -= dmg;
    if(this->hp <= 0){
        std::cout<< this->name << " has fainted!"<<std::endl;
        this->hp = 0;
    }
}
std::string Pokemon::getName(){
    return this->name;
}
PlayStyle * Pokemon::getStyle(){
    return this->style;
}
void Pokemon::setStyle(PlayStyle * style){
    this->style = style;
}
BattleState * Pokemon::getState(){
    return this->state;
}
void Pokemon::setState(BattleState * state){
    delete this->state;
    this->state = state;
}