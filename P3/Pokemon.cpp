#include "Pokemon.h"
//constructor
Pokemon::Pokemon()
{
    const std::string NAMES [] = {"Pikachu", "Bulbasaur", "Charmander", "Squirtle", "Pidgey", "Rattata", "Raticate", "Magikarp", "Gyarados", "Lapras", "Vaporeon", "Jolteon", "Flareon", "Eevee", "Snorlax"};
    this->name = NAMES[rand() % sizeof(NAMES)];
    this->dmg = rand() % 15 + 1;
    this->hp = rand() % 100 + 1;
    this->style = new RunPlayStyle();
    this->state = new NormalBattleState();
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
    std::cout << "Pokemon has died!" << std::endl;
}
//select battle state function
int Pokemon::SelectBattleState(){
    // this->state = this->state->getNextState(this->style);
    return this->state->handle(this->name, this->dmg);
}
//attack function
int Pokemon::attack(){
    if(this->hp <= 0){
        std::cout<< this->name << " hass fainted and cannot attack!"<<std::endl;
        return 0;
    }
    std::cout << this->name << " " << this->style->attack() << std::endl;
    this->dmg = this->state->handle(this->name, this->dmg);
    return this->dmg;
}