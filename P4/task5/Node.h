//Tayla Orsmond u21467456
//The Node class
//This class is used to specify a file or directory component
//The Node has a name
//The Node has an add() and remove function for files and directories
//The Node has a copy() method
//The node has an isEmpty() method
//The node has a list() method for files and directories
//The node has a createIterator() method
//The node has a showStructure() and a showContents() method
#pragma once
#include "NodeIterator.h"
#include "Observer.h"
#include <string>
using namespace std;
class File;
class Directory;

class Node
{
    public:
        Node(std::string name);
        void attatch(Observer * observer);
        void detatch(Observer * observer);
        void notify();
        void notify(std::string msg);
        void notify(std::string name, std::string contents);
        //getters and setters
        std::string getName();
        void setName(std::string name);
        std::string format;
        void setParent(Node * parent);
        Node * getParent();
        virtual ~Node();
        virtual void addFile(Node *node) = 0;
        virtual void addDirectory(Node *node) = 0;
        virtual void removeFile(std::string fileName) = 0;
        virtual void removeDirectory(std::string directoryName) = 0;
        virtual Node* copy() = 0;
        virtual bool isEmpty() = 0;
        virtual bool listFiles() = 0;
        virtual bool listDirectories() = 0;
        virtual NodeIterator * createIterator() = 0;
        virtual void showStructure() = 0;//depth first traversal
        virtual void showContents() = 0;//breadth first traversal
        virtual void setContents(std::string contents) = 0;
    private:
        std::string name;
        vector<Observer *> observers;
        friend class NodeIterator;
        Node * parent;
};

