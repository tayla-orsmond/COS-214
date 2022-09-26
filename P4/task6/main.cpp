//Tayla Orsmond u21467456
#include "Directory.h"
#include "DirectoryIterator.h"
#include "File.h"
#include "FileIterator.h"
#include "Node.h"
#include "NodeIterator.h"
#include "Root.h"
#include "Observer.h"
#include <typeinfo>

using namespace std;
int main(){
    //create a remake of a linux terminal with special commands
    //cd [name] for moving down the hirearchy
    //cd ../ for moving up the hirearchy
    //nf [name] for creating a new file in the directory and adding it
    //nd [name] for creating a new directory in the directory and adding it
    //rm [name] for removing a file or directory in the current directory
    //./ [name] for viewing a file or directory's contents
    //ls for viewing a file or directory's structure
    //nm [name] for changing a file or directory's name
    //ct [name] for changing a file's contents
    //cp [name] for creating a copy of a file or directory and adding it to it's parent directory
    //sn for creating a snapshot of the root directory
    //rs for restoring a snapshot of the root directory
    //cl for clearing all snapshots of the root directory
    //vs for viewing all snapshots of the root directory
    //ob for observing the current file
    //ex for exiting the program
    Root* root = new Root();//root of file system
    Node * current = root;//pointer up and down
    Observer* obs = new Observer();//observer for the file system
    root->protect(obs);
    string input, command, name;
    system("clear");
    cout<<"Welcome to the Linux Terminal Remake!"<<endl;
    cout<<"Commands: \n\tcd [name], \n\tcd ../, \n\tnf [name], \n\tnd [name], \n\trm [name], \n\t./ [name], \n\tls, \n\tnm [name], \n\tct [name], \n\tcp [name], \n\tsn, \n\trs, \n\tcl, \n\tvs, \n\tob, \n\tex"<<endl;
    do{
        //display the file path
        Node * path = current;
        vector<string> pathstr;
        cout<<"\u001b[1m\u001b[32mtayla@Martha\u001b[0m\u001b[1m:\u001b[34m~/";
        while(path != nullptr){
            pathstr.push_back(path->getName());
            path = path->getParent();
        }
        for(int i = pathstr.size()-1; i >= 0; i--){
            cout<<"\u001b[34m"<<pathstr[i];
            i == 0 ? cout<<"\u001b[0m$ " : cout<<"\u001b[34m/";
        }
        getline(cin, input);
        command = input.substr(0, input.find(" "));
        name = input.substr(input.find(" ")+1);
        if(command == "cd"){
            if(name == "../"){
                if(current->getParent() != nullptr){
                    current = current->getParent();
                }
            }
            else{
                NodeIterator* it = current->createDirectoryIterator();
                bool found = false;
                if(it != nullptr){
                    while(it->hasNext()){
                        if(it->current()->getName() == name){
                            current = it->current();
                            found = true;
                            break;
                        }
                        it->next();
                    }
                    delete it;
                    if(!found){
                        NodeIterator* it2 = current->createFileIterator();
                        while(it->hasNext()){
                            if(it2->current()->getName() == name){
                                current = it2->current();
                                found = true;
                                break;
                            }
                            it2->next();
                        }
                        delete it2;
                    }
                    if(!found){
                        cout<<"File or Directory with that name not found.\n";
                    }
                }
                else{
                    cout<<"Cannot cd into a file.\n";
                }
            }
        }
        else if(command == "nf"){
            Node * file = new File(name, name + " contents");
            current->addFile(file);
            if(typeid(*current) != typeid(File)){
                current = file;
            }
        }
        else if(command == "nd"){
            Node * dir = new Directory(name);
            current->addDirectory(dir);
            current = dir;
        }
        else if(command == "rm"){
            NodeIterator* it = current->createDirectoryIterator();
            bool found = false;
            if(it != nullptr){
                while(it->hasNext()){
                    if(it->current()->getName() == name){
                        current->removeDirectory(name);
                        found = true;
                        break;
                    }
                    it->next();
                }
                delete it;
                if(!found){
                    NodeIterator* it2 = current->createFileIterator();
                    while(it->hasNext()){
                        if(it2->current()->getName() == name){
                            current->removeFile(name);
                            found = true;
                            break;
                        }
                        it2->next();
                    }
                    delete it2;
                }
                if(!found){
                    cout<<"File or Directory with that name not found.\n";
                }
            }
        }
        else if(command == "./"){
            current->showContents();
        }
        else if(command == "ls"){
            current->showStructure();
        }
        else if(command == "nm"){
            current->setName(name);
        }
        else if(command == "ct"){
            current->setContents(name);
        }
        else if(command == "cp"){
            if(typeid(*current) == typeid(Root)){
                current->copy();
            }
            else if(typeid(*current) == typeid(File)){
                current->getParent()->addFile(current->copy());
            }
            else{
                current->getParent()->addDirectory(current->copy());
            }
        }
        else if(command == "sn"){
            root->takeSnapshot();
        }
        else if(command == "rs"){
            root->restoreSnapshot();
            current = root;
        }
        else if(command == "cl"){
            root->clearSnapshots();
        }
        else if(command == "vs"){
            root->viewSnapshots();
        }
        else if(command == "ob"){
            current->attatch(obs);
        }
        else if(command != "ex"){
            cout<<"Command not found.\n";
        }
    }while(command != "ex");
    current = nullptr;
    delete root;
    delete obs;
    return 0;
}