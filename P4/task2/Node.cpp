//Tayla Orsmond
#include "Node.h"
Node::Node(std::string name)
{
    this->name = name;
}
Node::~Node()
{
}
std::string Node::getName()
{
    return name;
}
void Node::setName(std::string name)
{
    if(name == "")
        return;
    this->name = name;
}
