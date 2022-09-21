//Tayla Orsmond u21467456
#include "DirectoryIterator.h"
DirectoryIterator::DirectoryIterator()
{
   
}
DirectoryIterator::~DirectoryIterator()
{
    
}
DirectoryIterator::DirectoryIterator(vector<Node*> directories):NodeIterator(directories)
{
    this->it = nodes->begin();
}
DirectoryIterator::DirectoryIterator(vector<Node*> directories, Node * firstNode, Node * currentNode) : NodeIterator(directories, firstNode, currentNode)
{
    this->it = nodes->begin();
}
Node * DirectoryIterator::current()
{
    return *it;
}
Node* DirectoryIterator::next()
{
    it++;
    return *it;
}
Node* DirectoryIterator::first()
{
    it = nodes->begin();
    return *it;
}
bool DirectoryIterator::hasNext()
{
    if(it == nodes->end())
    {
        return false;
    }
    return true;
}