//Tayla Orsmond u21467456
//The Directory class
//Inherits from Node
//The Directory class is used to specify a directory
//The Directory has a list of files and directories
//The Directory has a showStructure() method
//The Directory has a showContents() method
//The Directory has a copy() method
//The Directory has an isEmpty() method
#pragma once 
#include "Node.h"
#include "DirectoryIterator.h"
#include "FileIterator.h"
#include <iostream>
#include <string>
#include <vector>

class Directory : public Node
{
    public:
        Directory();
        Directory(std::string name);
        virtual ~Directory();
        void addFile(Node *node);
        void addDirectory(Node *node);
        void removeFile(std::string name);
        void removeDirectory(std::string name);
        Node* copy();
        bool isEmpty();
        bool listFiles();
        bool listDirectories();
        NodeIterator * createIterator();
        void showStructure();//depth first traversal
        void showContents();//breadth first traversal
        void setContents(std::string contents);
    private:
        std::vector<Node *> files;
        std::vector<Node *> directories;
        friend class DirectoryIterator;
        friend class FileIterator;
};