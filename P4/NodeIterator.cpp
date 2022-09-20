//Tayla Orsmond u21467456
#include "NodeIterator.h"

NodeIterator::NodeIterator()
{
    //constructor
    this->nodes = nullptr;
    this->firstNode = nullptr;
    this->currentNode = nullptr;
}
NodeIterator::~NodeIterator()
{
    //destructor
    // for(int i = 0; i < this->nodes->size(); i++)
    // {
    //     delete *(this->nodes->begin() + i);
    //     *(this->nodes->begin() + i) = nullptr;
    // }
    // delete this->nodes;
    this->nodes = nullptr;
    this->firstNode = nullptr;
    this->currentNode = nullptr;
}
NodeIterator::NodeIterator(vector<Node*> *v)
{
    this->nodes = v;
    this->firstNode = *(nodes->begin());
    this->currentNode = *(nodes->begin());
}
NodeIterator::NodeIterator(vector<Node*> *v, Node *firstNode, Node *currentNode)
{
    this->nodes = v;
    this->firstNode = firstNode;
    this->currentNode = currentNode;
}
void NodeIterator::setVector(vector<Node *> *v)
{
    this->nodes = v;
}