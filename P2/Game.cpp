#include "Game.h"
Game::Game(){

}
Game::~Game(){
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
    vector<Enemy *>::iterator e;
    for(e = enemies.begin(); e != enemies.end(); e++){
        delete *e;
    }
    if(finalBoss != nullptr){
        delete finalBoss;
        finalBoss = nullptr;
    }
}

void Game::restore(){
    enemies.back()->restore(finalBoss->retrieve());
    lives++;
    lvl = diff;
    diff++;
    win = false;
    this->play();
}
void Game::initialize(){
    std::cout<<setw(60)<<setfill('*')<<"\n";
    std::cout<<"\t\tWelcome to "<<GAMENAME<<"\n";
    std::cout<<setw(60)<<setfill('*')<<"\n";
    string difficulty ="";
    diff = 0;
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
    player = new SquadMember(name);
    barracks = new SquadStore();
    std::cout<<"\n\nAh of course, welcome "<<name<<".\n\tSetting up your game..."
    <<"\nYou chose difficulty "<<diff<<" so there will be "<<diff*2<<" levels.\n";

    lives = 5 - diff;
    clones.push_back(player->clone());
    diff *=2;
    lvl = 0;
    cout<<" | Lives: ";
    for(int i = 0; i < lives; i++){
        cout<<"<3 ";
        clones.push_back(clones.back()->clone());
    }
    std::cout<<"\n | HP: "<<player->getHP()<<"\n | DMG: "<<player->getDMG()
    <<"\n | Your weapon of choice is: "<<player->getATK()
    <<"\n | You choose "<<player->getDEF()<<" to defend yourself.\n";

    EnemyFactory * factories[4];
    factories[0] = new JaguarFactory();
    factories[1] = new CannibalFactory();
    factories[2] = new SnakeFactory();
    factories[3] = new GorillaFactory();
    for(int i = 0; i < diff; i++){
        enemies.push_back(factories[rand() % 4]->createEnemy(atks[rand()%SIZE], defs[rand()%SIZE]));
    }
    finalBoss = new EnemyStore();
    finalBoss->hide(enemies.back()->save());
    for(int i = 0; i < 4; i++){
        delete factories[i];
    }
}

void Game::play(){
    std::cout<<setw(60)<<setfill('-')<<"\n";
    std::cout<<"\t\tLet the games begin!\n";
    std::cout<<setw(60)<<setfill('-')<<"\n";
    quit = false, win = false;
    string c = "";
    int choice = 0, undoCount = 0;
    for(int i = lvl; i <= diff && lives >= 0 && !quit; i++)
    {
        std::cout<<"\n"<<setw(30)<<setfill('-')<<" LEVEL "<<i+1<<" "<<setw(30)<<setfill('-')<<"\n";
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
            <<"\t4 -> Quit.\n"
            <<"\t5 -> Save.\n";
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
                        if(enemies.size() > 1){
                            Enemy * deadEnemy = enemies.front();
                            delete deadEnemy;
                            deadEnemy = nullptr;
                            enemies.erase(enemies.begin());
                        }
                        else{
                            win = true;
                            quit = true;
                        }
                        lvl = i;
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
                    std::cout<<"Quitting game...\n";
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

}

bool Game::result(){
    if(win == true){
        std::cout<<"\n\n\t\tCongrats! You won Adventure Island!\n"
        <<"Would You like to restore the last enemy "<<enemies.back()->getName()<<" for one final battle?\n";
        char restore;
        string c;
        do{
            std::cout<<"\n[Y/N]\n";
            getline(cin, c);
            stringstream sss;
            sss<<c;
            sss>>restore;
            restore = toupper(restore);
            if(restore != 'Y' && restore != 'N'){
                std::cout<<"\nThis is a really simple question. Do you wanna fight or not?\n";
            }
        }while(restore != 'Y' && restore != 'N');
        if(restore == 'Y'){
            return true;
        }
    }
    else{
        std::cout<<"\n\n\t\tYou lost... Better luck next time!\n";
    }
    return false;
}



