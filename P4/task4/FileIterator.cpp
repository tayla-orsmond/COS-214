//Tayla Orsmond u21467456
#include "FileIterator.h"
using namespace std;

FileIterator::FileIterator()
{
    //constructor
}
FileIterator::~FileIterator()
{
    //destructor
}
FileIterator::FileIterator(vector<Node*> & files):NodeIterator(files)
{
    
}
Node * FileIterator::current()
{
    return *it;
}
Node* FileIterator::next()
{
    it++;
    return *it;
}
Node* FileIterator::first()
{
    it = nodes->begin();
    return *it;
}
bool FileIterator::hasNext()
{
    if(it == nodes->end())
    {
        return false;
    }
    return true;
}
