//Tayla Orsmond u214674576
//The NodeIterator class
//This is an abstract class that is used to iterate through the nodes in a directory
//The NodeIterator has a hasNext() method
//The NodeIterator has a next() method
//The NodeIterator has a first() method
//The NodeIterator has a current() method
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Node;

class NodeIterator
{   
    public:
        NodeIterator();
        NodeIterator(vector<Node *> v);
        NodeIterator(vector<Node*> v, Node *firstNode, Node *currentNode);
        void setVector(vector<Node *> v);
        vector<Node*>::iterator at(int i);
        virtual ~NodeIterator();
        virtual bool hasNext() = 0;
        virtual Node* next() = 0;
        virtual Node* first() = 0;
        virtual Node* current() = 0;
    protected:
        Node * firstNode;
        Node * currentNode;
        vector<Node *> * nodes;
    private:
        friend class Node;
};