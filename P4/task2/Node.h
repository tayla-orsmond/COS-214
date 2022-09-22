//Tayla Orsmond u21467456
//The Node class
//This class is used to specify a file or Folder component
//The Node has a name
//The Node has an add() and remove function for files and directories
//The Node has a copy() method
//The node has an isEmpty() method
//The node has a list() method for files and directories
//The node has a createIterator() method
//The node has a showStructure() and a showContents() method
#pragma once
#include <string>
class File;
class Folder;

class Node
{
    public:
        Node(std::string name);
        virtual ~Node();
        virtual void addFile(Node *node) = 0;
        virtual void addFolder(Node *node) = 0;
        virtual void removeFile(std::string fileName) = 0;
        virtual void removeFolder(std::string FolderName) = 0;
        virtual Node* copy() = 0;
        virtual bool isEmpty() = 0;
        virtual void listContents() = 0;
        //getters and setters
        std::string getName();
        void setName(std::string name);
        std::string format; 
    private:
        std::string name;
};

