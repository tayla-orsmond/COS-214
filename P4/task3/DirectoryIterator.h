//Tayla Orsmond u21467456
//The DirectoryIterator class
//Inherits from NodeIterator
//Iterates through the directories vector of the Directory class
//The DirectoryIterator class is a concrete iterator class that implements the Iterator interface.

#pragma once
#include "NodeIterator.h"
class Directory;

class DirectoryIterator : public NodeIterator
{
    public:
        DirectoryIterator();
        ~DirectoryIterator();
        DirectoryIterator(vector<Node*> & directories);
        Node * current();
        Node* next();
        Node* first();
        bool hasNext();
};