//Tayla Orsmond
#include "Node.h"
using namespace std;
Node::Node(string name)
{
    this->name = name;
}
Node::~Node()
{
}
string Node::getName()
{
    return name;
}
void Node::setName(string name)
{
    this->name = name;
}
