#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "SquadMember.h"
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
    
    cout<<setw(60)<<setfill('*')<<"\n";
    cout<<"\t\tWelcome to Adventure Island!\n";
    cout<<setw(60)<<setfill('*')<<"\n";
    string difficulty ="";
    int diff = 0;
    do{
        cout<<"\n Choose Your difficulty:\n"
        <<"\t1 -> Easy\n"
        <<"\t2 -> Meh\n"
        <<"\t3 -> Super Friggin' Hard!\n";
        getline(cin, difficulty);
        stringstream ss;
        ss<<difficulty;
        ss>>diff;
        switch(diff){
            case 1: cout<<"Ah, lookin' for some relaxin' I see...\n";
                break;
            case 2: cout<<"Ooh, a seasoned player! Exciting!\n";
                break;
            case 3: cout<<"You're lookin' to get ye bones broken aren't ye?\n";
                break;
            default: cout<<"\nWell that wasn't one of the options now, was it? Maybe you should pick 'easy'.\n";
        }
    }while(diff < 0 || diff > 3);

    cout<<"\n The adventure begins! What's your name, player?\n";
    string name ="";
    getline(cin, name);
    SquadMember * player = new SquadMember(name);
    cout<<"\nAh of course, welcome "<<name<<".\n\tSetting up your game..."
    <<"\nYou chose difficulty "<<diff<<" so there will be "<<diff*2<<" levels.\n";

    int lives = 5 - diff;
    //vector<SquadMember *> clones;
    //clones.push_back(player->clone());
    diff *=2;
    cout<<"\tLives: ";
    for(int i = 0; i < lives; i++){
        cout<<"<3 ";
        //clones.push_back(clones.back()->clone());
    }
    cout<<"\n\tHP: "<<player->getHP()<<"\n\tDMG: "<<player->getDMG()
    <<"\n Your weapon of choice is: "<<player->getATK()
    <<"\n You choose "<<player->getDEF()<<" to defend yourself.\n";
    vector<Enemy *> enemies;
    EnemyFactory * factories[4];
    factories[0] = new JaguarFactory();
    factories[1] = new CannibalFactory();
    factories[2] = new SnakeFactory();
    factories[3] = new GorillaFactory();
    for(int i = 0; i < diff; i++){
        enemies.push_back(factories[rand() % 4]->createEnemy(atks[rand()%SIZE], defs[rand()%SIZE]));
    }

    cout<<setw(60)<<setfill('-')<<"\n";
    cout<<"\t\tLet the games begin!\n";
    cout<<setw(60)<<setfill('-')<<"\n";
    bool quit = false;
    string c = "";
    int choice = 0;
    for(int i = 1; i <= diff && lives > 0 && !quit; i++)
    {
        cout<<setw(30)<<setfill('-')<<" LEVEL "<<i<<" "<<setw(30)<<setfill('-')<<"\n";
        cout<<"A wild "<<enemies.front()->getName()<<" appears!\n"
        <<"ATK: "<<enemies.front()->getATK()
        <<" which has a DMG of: "<<enemies.front()->getDMG()
        <<"\nDEF: "<<enemies.front()->getDEF()<<endl;

        cout<<setw(20)<<setfill('_')<<"\n"
        <<"\t"<<player->getName()<<" stats:\n"
        <<"\n\tLives: ";
        for(int i = 0; i < lives; i++){
            cout<<"<3 ";
        }
        cout<<"\n\tHP: "<<player->getHP()
        <<"\n\tDMG: "<<player->getDMG()<<endl;

        do{
            cout<<"\n Choose An Action:\n"
            <<"\t1 -> Heal\n"
            <<"\t2 -> Train\n"
            <<"\t3 -> Fight!\n"
            <<"\t4 -> Quit.\n";
            getline(cin, c);
            stringstream ss;
            ss<<c;
            ss>>choice;
            switch(choice){
                case 1: {
                    cout<<"You decide to take some time to heal up.\n";
                    player->setHP(player->getHP()+(rand() % 4)+1);
                    i--;
                }
                    break;
                case 2:{
                    cout<<"You decide to train up your moves\n";
                    player->setDMG(player->getDMG()+(rand() % 4)+1);
                    i--;
                }
                    break;
                case 3:{
                    cout<<"Time to FIGHT!!!\n";
                    enemies.front()->attack(player);
                    if(enemies.front()->getHP() == 0){
                        cout<<"\n\tCongrats! Enemy "<<enemies.front()->getName()<<" defeated!\n";
                        Enemy * deadEnemy = enemies.front();
                        delete deadEnemy;
                        deadEnemy = nullptr;
                        enemies.erase(enemies.begin());
                    }
                    else if(player->getHP() == 0){
                        cout<<"\n\tYou have been defeated!\n"
                        <<"You see a bright light coming toward you...";
                        if(lives > 0){
                            SquadMember * clone = player->clone();
                            delete player;
                            player = clone;
                            clone = nullptr;
                            //player = clones.front();
                            //clones.erase(clones.begin());
                            cout<<"\n\t\t...Someone takes your place!"
                            <<"\n\t[Used 1 Life!]\n";
                            lives--;
                            i--;
                        }
                        else{
                            cout<<"\n\t\t...There's no more clones to save you!\n";
                            //undo mech?
                            quit = true;
                        }
                    }
                }
                    break;
                case 4: {
                    cout<<"Quitting game...";
                    quit = true;
                }
                    break;
                default: cout<<"\nYou seriously can't follow instructions, can you? Maybe you should quit the game now (hint: that's option 4).\n";
            }
        }while(!quit && (choice < 0 || choice > 4));
    }
    if(enemies.size() == 0 && (player->getHP() > 0 || lives > 0)){
        cout<<"\n\n\tCongrats! You won Adventure Island!\n";
    }
    else{
        cout<<"\n\n\tYou lost... Better luck next time!\n";
    }

    cout<<setw(60)<<setfill('*')<<"\n";
    cout<<"\t\tThank you for playing!\n";
    cout<<setw(60)<<setfill('*')<<"\n";

    if(player != nullptr){
        delete player;
        player = nullptr;
    }
    // if(clones.size() > 0){
    //     vector<SquadMember *>::iterator i;
    //     for(i = clones.begin(); i != clones.end(); i++){
    //         delete *i;
    //     }
    // }
    for(int i = 0; i < 4; i++){
        delete factories[i];
    }
    vector<Enemy *>::iterator e;
    for(e = enemies.begin(); e != enemies.end(); e++){
        delete *e;
    }
    return 0;
}