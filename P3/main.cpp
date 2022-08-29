#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Cadbury.h"
#include "Nestle.h"
#include "Lindt.h"

using namespace std;

int main(){
    //create factories
    std::cout<<"=========================="<<std::endl
                <<"|  TASK 1 & 2    |"<<std::endl
                <<"=========================="<<std::endl;
    std::cout<<"Welcome to the Chocolate Factory!"<<endl;
    ConfectioneryFactory ** factories = new ConfectioneryFactory *[3];
    factories[0] = new Cadbury();
    factories[1] = new Nestle();
    factories[2] = new Lindt();
    //create products vector
    const int MAX_PRODUCTS = 10;
    Confectionery ** chocolates = new Confectionery *[MAX_PRODUCTS];
    //choice
    std::string choice;
    int f, c, s, b, count = 0;//factory, chocolate, slab, bubblespccm, counter
    do{
        //print out products (vector)
        std::cout<<"\n\nInventory: "<<(*chocolates)->getCount()<<"/20"<<endl;
        for(int i = 0; i != (*chocolates)->getCount(); i++){
            if(chocolates[i] != nullptr)
                std::cout<<chocolates[i]->getDescription()<<endl;
            else{
                std::cout<<"Empty chocolate."<<endl;
            }
        }
        //choice for creating chocolates (manufacturer)
        std::cout<<"\nPlease choose a factory:"<<endl
        <<"[0]. Cadbury"<<endl
        <<"[1]. Nestle"<<endl
        <<"[2]. Lindt"<<endl
        <<"[3]. Exit"<<endl;
        std::cin>>choice;
        f = stoi(choice);
        if(f>=0 && f<=2){
            //choice for creating chocolates (chocolate)
            std::cout<<"Please choose a chocolate:"<<endl
            <<"[0]. Chocolate"<<endl
            <<"[1]. Aerated Chocolate"<<endl;
            std::cin>>choice;
            c = stoi(choice);
            switch(c){
                case 0:
                    //choice for creating chocolates (slab)
                    bool slab;
                    std::cout<<"Do you want a slab or a bar?"<<endl
                    <<"[0]. Slab"<<endl
                    <<"[1]. Bar"<<endl;
                    std::cin>>choice;
                    s = stoi(choice);
                    slab = s==0 ? true : false;
                    chocolates[count++] = (factories[f]->createChocolate(slab));
                    break;
                case 1:
                    //choice for creating chocolates (bubbles)
                    std::cout<<"Please enter the amount of bubbles per cm:"<<endl;
                    std::cin>>choice;
                    b = stoi(choice);
                    chocolates[count++] = (factories[f]->createAeratedChocolate(b));
                    if(chocolates[count-1] == nullptr){
                        std::cout<<"Lindt does not make this chocolate."<<endl;
                        count--;
                    }
                    break;
                default:
                    std::cout<<"Invalid choice"<<endl;
                    break;
            }
        }
        else if(f==3){
            std::cout<<"Goodbye!\n\n"<<endl;
        }
        else{
            std::cout<<"Invalid choice"<<endl;
        }
    }while(f != 3 && (*chocolates)->getCount() < MAX_PRODUCTS);
    //deallocate memory
    for(int i = 0; i != (*chocolates)->getCount(); i++){
        if(chocolates[i] != nullptr)
            delete chocolates[i];
    }
    delete [] chocolates;
    chocolates = nullptr;
    for(int i = 0; i != 3; i++){
        delete factories[i];
    }
    delete [] factories;
    factories = nullptr;
    return 0;
}