//Tayla Orsmond u21467456
#include "NodeIterator.h"

NodeIterator::NodeIterator()
{
    //constructor
    this->nodes = nullptr;
}
NodeIterator::~NodeIterator()
{
    //destructor
    // for(int i = 0; i < this->nodes.size(); i++)
    // {
    //     delete *(this->nodes.begin() + i);
    //     *(this->nodes.begin() + i) = nullptr;
    // }
    this->nodes = nullptr;
}
NodeIterator::NodeIterator(vector<Node*> & v)
{
    this->nodes = &v;
    this->it = nodes->begin();
}
void NodeIterator::setVector(vector<Node *> & v)
{
    this->nodes = &v;
    this->it = nodes->begin();
}
vector<Node *>::iterator NodeIterator::at(int i){
    this->it = this->nodes->begin() + i;
    return it;
}