#include "Pokemon.h"
//constructor
Pokemon::Pokemon()
{
    const std::string NAMES [] = {"Pikachu", "Bulbasaur", "Charmander", "Squirtle", "Pidgey", "Rattata", "Raticate", "Magikarp", "Gyarados", "Lapras", "Vaporeon", "Jolteon", "Flareon", "Eevee", "Snorlax"};
    this->name = NAMES[rand() % sizeof(NAMES)];
    this->dmg = rand() % 40 + 1;
    this->hp = rand() % 100 + 1;
    this->state = new NormalBattleState();
    std::cout << "\t\t\t\t" << this->name << " has been born" << std::endl;
}
//parameterized constructor
Pokemon::Pokemon(std::string name, int dmg, int hp, PlayStyle * style)
{
    this->name = name;
    this->dmg = dmg;
    this->hp = hp;
    this->style = style;
    this->state = new NormalBattleState();
}
//destructor
Pokemon::~Pokemon()
{
    std::cout << "\t\t\t\tPokemon has died!" << std::endl;
}
//select battle state function
int Pokemon::SelectBattleState(){
    return this->state->handle(this, this->style->getStyle());
}
//attack function
int Pokemon::attack(){
    if(this->hp <= 0){
        std::cout<< this->name << " hass fainted and cannot attack!"<<std::endl;
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