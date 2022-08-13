#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include "SquadMember.h"
#include "SquadStore.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "Cannibal.h"
#include "CannibalFactory.h"
#include "Gorilla.h"
#include "GorillaFactory.h"
#include "Jaguar.h"
#include "JaguarFactory.h"
#include "Snake.h"
#include "SnakeFactory.h"
using namespace std;

int main(){
    srand(time(nullptr));
    const int SIZE = 7;
    string atks[SIZE] = {"a bow and arrow", "a vicious scream", "another coffee mug", "a boulder", "a plakkie", "sparkles!!!", "a COS semester test"};
    string defs[SIZE] = {"an uno reverse card", "a really big umbrella", "giving you a stern talking to", "a backhand", "a Barricade", "a plastic bubble that 'looks like a disco ball'"};
    
    std::cout<<setw(60)<<setfill('*')<<"\n";
    std::cout<<"\t\tWelcome to Adventure Island!\n";
    std::cout<<setw(60)<<setfill('*')<<"\n";
    string difficulty ="";
    int diff = 0;
    do{
        std::cout<<"\n Choose Your difficulty:\n"
        <<"\t1 -> Easy\n"
        <<"\t2 -> Meh\n"
        <<"\t3 -> Super Friggin' Hard!\n";
        getline(std::cin, difficulty);
        stringstream ss;
        ss<<difficulty;
        ss>>diff;
        switch(diff){
            case 1: std::cout<<"Ah, lookin' for some relaxin' I see...\n";
                break;
            case 2: std::cout<<"Ooh, a seasoned player! Exciting!\n";
                break;
            case 3: std::cout<<"You're lookin' to get ye bones broken aren't ye?\n";
                break;
            default: std::cout<<"\nWell that wasn't one of the options now, was it? Maybe you should pick 'easy'.\n";
        }
    }while(diff < 0 || diff > 3);

    std::cout<<"\nThe adventure begins! What's your name, player?\n";
    string name ="";
    getline(std::cin, name);
    SquadMember * player = new SquadMember(name);
    SquadStore * barracks = new SquadStore();
    std::cout<<"\n\nAh of course, welcome "<<name<<".\n\tSetting up your game..."
    <<"\nYou chose difficulty "<<diff<<" so there will be "<<diff*2<<" levels.\n";

    int lives = 5 - diff;
    vector<SquadMember *> clones;
    clones.push_back(player->clone());
    diff *=2;
    cout<<"|\t\tLives: ";
    for(int i = 0; i < lives; i++){
        cout<<"<3 ";
        clones.push_back(clones.back()->clone());
    }
    std::cout<<"\n|\t\tHP: "<<player->getHP()<<"\n\t\tDMG: "<<player->getDMG()
    <<"\n|\tYour weapon of choice is: "<<player->getATK()
    <<"\n|\tYou choose "<<player->getDEF()<<" to defend yourself.\n";

    vector<Enemy *> enemies;
    EnemyFactory * factories[4];
    factories[0] = new JaguarFactory();
    factories[1] = new CannibalFactory();
    factories[2] = new SnakeFactory();
    factories[3] = new GorillaFactory();
    for(int i = 0; i < diff; i++){
        enemies.push_back(factories[rand() % 4]->createEnemy(atks[rand()%SIZE], defs[rand()%SIZE]));
    }

    std::cout<<setw(60)<<setfill('-')<<"\n";
    std::cout<<"\t\tLet the games begin!\n";
    std::cout<<setw(60)<<setfill('-')<<"\n";
    bool quit = false;
    string c = "";
    int choice = 0, undoCount = 0;
    for(int i = 1; i <= diff && lives >= 0 && !quit; i++)
    {
        std::cout<<"\n"<<setw(30)<<setfill('-')<<" LEVEL "<<i<<" "<<setw(30)<<setfill('-')<<"\n";
        std::cout<<"A wild "<<enemies.front()->getName()<<" appears!\n"
        <<"ATK: "<<enemies.front()->getATK()
        <<" which has a DMG of: "<<enemies.front()->getDMG()
        <<"\nDEF: "<<enemies.front()->getDEF()<<endl;

        std::cout<<setw(40)<<setfill('_')<<"\n"
        <<player->getName()<<" stats:\n"
        <<"\n\tLives: ";
        for(int i = 0; i < lives; i++){
            std::cout<<"<3 ";
        }
        std::cout<<"\n\tHP: "<<player->getHP()
        <<"\n\tDMG: "<<player->getDMG()<<endl;

        do{
            std::cout<<"\nChoose An Action:\n"
            <<"\t1 -> Heal\n"
            <<"\t2 -> Train\n"
            <<"\t3 -> Fight!\n"
            <<"\t4 -> Quit.\n";
            getline(std::cin, c);
            stringstream ss;
            ss<<c;
            ss>>choice;
            switch(choice){
                case 1: {
                    std::cout<<"\t\t\tYou decide to take some time to heal up.\n";
                    player->setHP(player->getHP()+(rand() % 4)+1);
                    i--;
                    barracks->store(player->save(choice));
                }
                    break;
                case 2:{
                    std::cout<<"\t\t\tYou decide to train up your moves\n";
                    player->setDMG(player->getDMG()+(rand() % 4)+1);
                    i--;
                    barracks->store(player->save(choice));
                }
                    break;
                case 3:{
                    std::cout<<"Time to FIGHT!!!\n";
                    enemies.front()->attack(player);
                    if(enemies.front()->getHP() <= 0){
                        std::cout<<"\n\nCongrats! Enemy "<<enemies.front()->getName()<<" defeated!\n";
                        Enemy * deadEnemy = enemies.front();
                        delete deadEnemy;
                        deadEnemy = nullptr;
                        enemies.erase(enemies.begin());
                        barracks->store(player->save(choice));
                    }
                    else if(player->getHP() <= 0){
                        std::cout<<"\n\nYou have been defeated!\n"
                        <<"You see a bright light coming toward you...";
                        if(lives > 0){
                            SquadMember * clone = clones.front();
                            delete player;
                            player = clone;
                            clone = nullptr;
                            clones.erase(clones.begin());
                            std::cout<<right<<"\n\t\t\t\t...Someone takes your place!\n"
                            <<"[Used 1 Life!]\n";
                            lives--;
                            i--;
                            barracks->store(player->save(choice));
                        }
                        else{
                            std::cout<<"\n\t\t\t\t...There's no more clones to save you!\n"
                            <<"\nWould you like to undo to your previous move? (You can only do this once!)";
                            char undo;
                            do{
                                std::cout<<"\n[Y/N]\n";
                                getline(cin, c);
                                stringstream sss;
                                sss<<c;
                                sss>>undo;
                                undo = toupper(undo);
                                if(undo != 'Y' && undo != 'N'){
                                    std::cout<<"\nThis is a really simple question. I don't know why you're having such a hard time with this.\n";
                                }
                            }while(undo != 'Y' && undo != 'N');
                            if(undo == 'N'){quit = true;}
                            else{
                                if(barracks->size() > 0 && undoCount == 0){
                                    player->restore(barracks->restore());
                                    i--;
                                    undoCount++;
                                    continue;
                                }
                                else{
                                    std::cout<<"\nLooks like there's no moves to undo to!\n";
                                    quit = true;
                                }
                            }
                        }
                    }
                }
                    break;
                case 4: {
                    std::cout<<"Quitting game...";
                    quit = true;
                }
                    break;
                default: {
                    std::cout<<"\nYou seriously can't follow instructions, can you? Maybe you should quit the game now (hint: that's option 4).\n";
                    i--;
                }
            }
        }while(!quit && (choice < 0 || choice > 4));
    }
    if(enemies.size() == 0 && (player->getHP() > 0 || lives > 0)){
        std::cout<<"\n\n\t\tCongrats! You won Adventure Island!\n";
    }
    else if(quit == true){
        std::cout<<"\n\n\t\tSee You next time!\n";
    }
    else{
        std::cout<<"\n\n\t\tYou lost... Better luck next time!\n";
    }

    std::cout<<setw(60)<<setfill('*')<<"\n";
    std::cout<<"\t\tThank you for playing!\n";
    std::cout<<setw(60)<<setfill('*')<<"\n";

    if(player != nullptr){
        delete player;
        player = nullptr;
    }
    vector<SquadMember *>::iterator i;
    for(i = clones.begin(); i != clones.end(); i++){
        delete *i;
    }
    for(int i = 0; i < 4; i++){
        delete factories[i];
    }
    vector<Enemy *>::iterator e;
    for(e = enemies.begin(); e != enemies.end(); e++){
        delete *e;
    }
    return 0;
}