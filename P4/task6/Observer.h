//Tayla Orsmond u21467456
//The Observer class
//This class is used to specify an observer to observe a Node
//The observer has a update() method
#pragma once
#include <iostream>
#include <string>
#include <cstring>
class Node;
class Observer
{
    public:
        void update(){
            std::cout<<"Update: Node has been updated"<<std::endl;
        }
        void update(std::string msg){
            std::cout<<"Update: "<<msg<<std::endl;
        }
        void update(std::string name, std::string contents){
            //virus checker
            //check if name or contents strings contain the string "cos 214"
            //if they do, print a message to the console
            //if they don't, print a message to the console
            if(name.find("cos 214") != std::string::npos || contents.find("cos 214") != std::string::npos)
            {
                std::cout<<"!!! Update: Virus detected in "<<name<<"!!!"<<std::endl;
            }
            //check if name or contents strings contain the string "cos214"
            //if they do, print a message to the console
            //if they don't, print a message to the console
            else if(name.find("cos214") != std::string::npos || contents.find("cos214") != std::string::npos)
            {
                std::cout<<"!!! Update: Virus detected in "<<name<<"!!!"<<std::endl;
            }
            else
            {
                std::cout<<"Update: No virus detected in "<<name<<std::endl;
            }
        }
};