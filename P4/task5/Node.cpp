//Tayla Orsmond
#include "Node.h"
using namespace std;
Node::Node(string name)
{
    this->name = name;
}
Node::~Node()
{
    // for(int i = 0; i < observers.size(); i++)
    // {
    //     delete observers[i];
    // }
}
string Node::getName()
{
    return name;
}
void Node::setName(string name)
{
    if(name != "")
    {
        this->name = name;
        this->notify(this->getName(), "");
    }
}
void Node::attatch(Observer * observer)
{
    observers.push_back(observer);
}
void Node::detatch(Observer * observer)
{
    for(int i = 0; i < observers.size(); i++)
    {
        if(observers[i] == observer)
        {
            //delete observers[i];
            observers.erase(observers.begin() + i);
        }
    }
}
void Node::notify()
{
    if(observers.size() > 0)
    {
        cout<<this->getName()<<" notified v\n";
        for(int i = 0; i < observers.size(); i++)
        {
            observers[i]->update();
        }
    }
    else{
        cout<<this->getName()<<" notified ^\n";
    }
    if(parent != nullptr)
    {
        parent->notify();
    }
}
void Node::notify(string msg)
{
    if(observers.size() > 0)
    {
        cout<<this->getName()<<" notified v\n";
        for (int i = 0; i < observers.size(); i++)
        {
            cout<<"\t";
            observers[i]->update(msg);
        }
    }
    else{
        cout<<this->getName()<<" notified ^\n";
    }
    if(parent != nullptr)
    {
        parent->notify(msg);
    }
}
void Node::notify(string name, string contents)
{
    if(observers.size() > 0)
    {
        cout<<this->getName()<<" notified v\n";
        for (int i = 0; i < observers.size(); i++)
        {
            cout<<"\t";
            observers[i]->update(name, contents);
        }
    }
    else{
        cout<<this->getName()<<" notified ^\n";
    }
    if(parent != nullptr)
    {
        parent->notify(name, contents);
    }
}
void Node::setParent(Node * node)
{
    this->parent = node;
}
Node * Node::getParent()
{
    return parent;
}