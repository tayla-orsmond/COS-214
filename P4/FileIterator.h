//Tayla Orsmond u21467456
//The FileIterator class
//Inherits from NodeIterator
//The File Iterator class is used to iterate through a list of files
//The FileIterator has a setVector() method
//The FileIterator has a current() method
//The FileIterator has a next() method
//The FileIterator has a first() method
//The FileIterator has a hasNext() method
#pragma once
#include "NodeIterator.h"
#include <vector>
#include <iostream>
using namespace std;

class FileIterator : public NodeIterator
{
    public:
        FileIterator();
        ~FileIterator();
        FileIterator(vector<Node*> files);
        FileIterator(vector<Node*> files, Node * firstNode, Node * currentNode);
        void setVector(vector<Node*> files);
        Node * current();
        Node* next();
        Node* first();
        bool hasNext();
    private:
        vector<Node*>::iterator it;
        vector<Node*> files;
};