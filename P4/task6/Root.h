//Tayla Orsmond u21467456
//The Root class
//Inherits from Directory
//A special kind of Directory that acts as the Root of the file system
//Allows a user to take snapshots (make copies) of the file system
//Allows a user to restore snapshots of the file system
//Allows a user to clear all snapshots of the file system
//Allows a user to view all snapshots of the file system
#pragma once
#include "Directory.h"
#include <string>
#include <vector>

class Root: public Directory{
    public:
        Root();
        Root(std::string name);
        ~Root();
        void takeSnapshot();
        void restoreSnapshot();
        void clearSnapshots();
        void viewSnapshots();
        void addFile(Node *node);
        void addDirectory(Node *node);
        void removeFile(std::string name);
        void removeDirectory(std::string name);
        bool isEmpty();
        bool listFiles();
        bool listDirectories();
        NodeIterator * createIterator();
        void showStructure();//depth first traversal
        void showContents();//breadth first traversal
    private:
        vector<Node *> snaps;
        Node * root;
};