//Tayla Orsmond u21467456
#include "Root.h"

Root::Root(){
    root = new Directory("root");
}
Root::Root(std::string name){
    root = new Directory(name);
}
Root::~Root(){
    delete root;
}
void Root::takeSnapshot(){
    snaps.push_back(root->copy());
}
void Root::restoreSnapshot(){
    if(snaps.size() > 0){
        delete root;
        root = snaps.back();
        snaps.pop_back();
    }
}
void Root::clearSnapshots(){
    for(int i = 0; i < snaps.size(); i++){
        delete snaps[i];
    }
    snaps.clear();
}
void Root::viewSnapshots(){
    for(int i = 0; i < snaps.size(); i++){
        cout <<i+1<<". "<< snaps[i]->getName() << endl;
    }
}
void Root::addFile(Node *node){
    root->addFile(node);
}
void Root::addDirectory(Node *node){
    root->addDirectory(node);
}
void Root::removeFile(std::string name){
    root->removeFile(name);
}
void Root::removeDirectory(std::string name){
    root->removeDirectory(name);
}
bool Root::isEmpty(){
    return root->isEmpty();
}
bool Root::listFiles(){
    return root->listFiles();
}
bool Root::listDirectories(){
    return root->listDirectories();
}
NodeIterator * Root::createIterator(){
    return root->createIterator();
}
void Root::showStructure(){
    root->showStructure();
}
void Root::showContents(){
    root->showContents();
}
