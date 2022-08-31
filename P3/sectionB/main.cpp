#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include "Pokemon.h"
#include "PhysicalAttackPlayStyle.h"
#include "RunPlayStyle.h"
#include "AttackPlayStyle.h"
using namespace std;

int main(){
    //create a pokemon
    srand(time(NULL));
    std::cout<<std::setw(100)<<std::setfill('=')<<"\n";
    std::cout<<"\t\tChoose your Pokemon!"<<std::endl;
    std::cout<<std::setw(100)<<std::setfill('=')<<"\n";
    string choice;
    int c;
    do{
        std::cout<<"\t\tEnter your choice: ";
        std::cout<<"\n\t\t1. Small team"<<std::endl;
        std::cout<<"\t\t2. Med team"<<std::endl;
        std::cout<<"\t\t3. Large team"<<std::endl;
        std::cout<<"\t\t4. Quit"<<std::endl;
        getline(cin, choice);
        c = stoi(choice) -1;
        switch(c){
            case 0:
                std::cout<<"\t\tYou have chosen a Small team"<<std::endl;
                break;
            case 1:
                std::cout<<"\t\tYou have chosen a Med team"<<std::endl;
                break;
            case 2:
                std::cout<<"\t\tYou have chosen a Large team"<<std::endl;
                break;
            case 3:
                std::cout<<"\t\tGoodbye!"<<std::endl;
                break;
            default:
                std::cout<<"\t\tInvalid choice"<<std::endl;
                break;
        }
    }while(c != 3 && c != 2 && c != 1 && c != 0);
    if(c != 3){
        const int SIZE = c + 3;
        int teamsize = SIZE;
        int remainingenemies = SIZE;
        Pokemon ** team = new Pokemon*[SIZE];
        Pokemon ** enemyTeam = new Pokemon*[SIZE];
        for(int i = 0; i < SIZE; i++){
            std::cout<<"\t\tEnter your Pokemon's name: ";
            string name;
            getline(cin, name);
            string attackStyle;
            PlayStyle * style;
            PlayStyle * enemyStyle;
            int atk;
            do{
                std::cout<<"\t\tEnter a playstyle for your Pokemon: "
                <<"\n\t\t1. Physical Attack"<<std::endl
                <<"\t\t2. Normal Attack"<<std::endl
                <<"\t\t3. Run"<<std::endl;
                getline(cin, attackStyle);
                atk = stoi(attackStyle) -1;
                switch(atk){
                    case 0:
                        std::cout<<"\t\tYou have chosen Physical Attack"<<std::endl;
                        style = new PhysicalAttackPlayStyle();
                        break;
                    case 1:
                        std::cout<<"\t\tYou have chosen Normal Attack"<<std::endl;
                        style = new AttackPlayStyle();
                        break;
                    case 2:
                        std::cout<<"\t\tYou have chosen Run"<<std::endl;
                        style = new RunPlayStyle();
                        break;
                    default:
                        std::cout<<"\t\tInvalid choice"<<std::endl;
                        break;
                }

            }while(atk != 0 && atk != 1 && atk != 2);
            int hp = (rand() % 100) + 1;
            int dmg = (rand() % 30) + 1;
            team[i] = new Pokemon(name, dmg, hp, style, new NormalBattleState());
            std::cout<<"Creating enemy pokemon..."<<std::endl;
            int st = rand() % 3 + 1;
            switch(st){
                case 1:
                    enemyStyle = new PhysicalAttackPlayStyle();
                    break;
                case 2:
                    enemyStyle = new AttackPlayStyle();
                    break;
                default:
                    enemyStyle = new RunPlayStyle();
                    break;
            }
            enemyTeam[i] = new Pokemon(new NormalBattleState(), enemyStyle);
        }
        std::cout<<std::setw(100)<<std::setfill('=')<<"\n";
        std::cout<<"\t\tLet the Games begin!"<<std::endl;
        std::cout<<std::setw(100)<<std::setfill('=')<<"\n\n";
        bool quit = false;
        int i = 0;
        int allowedturns = 1, enemyturns = 1;
        while(i < SIZE && !quit){
            std::cout<<"\n\t\tA wild "<<enemyTeam[i]->getName()<<" appears!"<<std::endl
            <<"\t\tHP: "<<enemyTeam[i]->getHP()<<std::endl
            <<"\t\tDamage: "<<enemyTeam[i]->getDmg()<<std::endl;
            std::cout<<std::setw(100)<<std::setfill('_')<<"\n";

            std::cout<<"\tYour team:"<<std::endl;
            for(int j = 0; j < SIZE; j++){
                std::cout<<"\t"<<j+1<<"."<<team[j]->getName();
                if(team[j]->getHP() <= 0){
                    std::cout<<" (fainted)";
                }
                std::cout<<std::endl;
            }
            std::cout<<std::setw(100)<<std::setfill('_')<<"\n";
            string pokemon;
            int p;
            do{
                std::cout<<"\t\tChoose a pokemon to battle with: [1-"<<SIZE<<"]"<<std::endl
                <<"\t\tOr choose 0 to quit"<<std::endl;
                std::cin>>pokemon;
                p = stoi(pokemon) -1;
                if(p == -1){
                    quit = true;
                    break;
                }
                if(p < 0 || p >= SIZE){
                    std::cout<<"\t\tInvalid choice"<<std::endl;
                }
            }while(p < 0 && p >= SIZE && !quit);
            if(quit){
                break;
            }
            std::cout<<"\tYou have chosen "<<team[p]->getName()<<std::endl;
            std::cout<<"\tHP: "<<team[p]->getHP()<<std::endl
            <<"\tDamage: "<<team[p]->getDmg()<<std::endl<<std::endl;
            allowedturns = 1;
            enemyturns = 1;
            if(team[p]->getStyle()->getStyle() == "physical"){
                enemyturns = 2;
            }
            else if(team[p]->getStyle()->getStyle() == "run"){
                allowedturns = 2;
            }
            for(int t = 0; t < allowedturns; t++){
                int result = team[p]->attack();
                if(result == 0){
                    i--;
                    break;
                }
                enemyTeam[i]->takeDmg(result);
            }
            if(team[p]->getHP() > 0 && enemyTeam[i]->getHP() > 0){
                for(int t = 0; t < enemyturns; t++){
                    team[p]->takeDmg(enemyTeam[i]->attack());
                    if(team[p]->getHP() <= 0){
                        teamsize--;
                        break;
                    }
                }
            }
            else{
                remainingenemies--;
                i++;
            }
            if(teamsize == 0){
                std::cout<<"\t\tSorry, You lost!"<<std::endl;
                quit = true;
            }
            if(remainingenemies == 0){
                std::cout<<"\t\tCongrats! You won!"<<std::endl;
                quit = true;
            }
        }
        //deallocate memory
        for(int i = 0; i < SIZE; i++){
            if(team[i] != NULL){
                delete team[i];
            }
        }
        delete [] team;
        for(int i = 0; i < SIZE; i++){
            if(enemyTeam[i] != NULL){
                delete enemyTeam[i];
            }
        }
        delete [] enemyTeam;
    }
    std::cout<<"\t\tThank you for playing!"<<std::endl;
    return 0;
}