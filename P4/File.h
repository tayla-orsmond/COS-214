//Tayla Orsmond u21467456
//The File class 
//Inherits from the abstract class Node
//Contains a name(inherited from Node) and a contents
//The File has a copy() method
//The File has an isEmpty() method
//The File has a list() method
//The File has a createIterator() method
//The File has a showStructure() and a showContents() method
#pragma once
#include "Node.h"
#include "FileIterator.h"
#include <iostream>
#include <string>
using namespace std;

class Directory;
class File : public Node
{
    public:
        File();
        File(std::string name, std::string contents);
        ~File();
        void addFile(File *node);
        void addDirectory(Directory *node);
        void removeFile(std::string name);
        void removeDirectory(std::string name);
        Node* copy();
        bool isEmpty();
        bool listFiles();
        bool listDirectories();
        NodeIterator * createIterator();
        void showStructure();
        void showContents();
        //getters and setters
        std::string getContents();
        void setContents(std::string contents);
    private:
        std::string contents;
        friend class FileIterator;
};