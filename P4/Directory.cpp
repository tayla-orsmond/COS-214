//Tayla Orsmond u21467456
#include "Directory.h"
using namespace std;
Directory::Directory(): Node("New Directory")
{
    cout<<this->getName()<<" created"<<endl;
}
Directory::Directory(string name) : Node(name)
{
    cout<<this->getName()<<" created"<<endl;
}
Directory::~Directory()
{
    cout<<"Directory deleted."<<endl;
}
void Directory::addFile(Node *node)
{
    files.push_back(node);
}
void Directory::addDirectory(Node * node)
{
    directories.push_back(node);
}
void Directory::removeFile(std::string name)
{
    if(files.size() == 0)
    {
        cout<<"No files to remove."<<endl;
        return;
    }
    NodeIterator * it = files[0]->createIterator();
    it->setVector(files);
    int i = 0;
    while(it->hasNext())
    {
        if(it->current()->getName() == name)
        {
            delete it->current();
            files.erase(it->at(i));
            delete it;
            return;
        }
        it->next();
        i++;
    }
    delete it;
    cout<<"File not found."<<endl;
}
void Directory::removeDirectory(std::string name)
{
    if(directories.size() == 0)
    {
        cout<<"No directories to remove."<<endl;
        return;
    }
    NodeIterator * it = directories[0]->createIterator();
    it->setVector(directories);
    int i = 0;
    while(it->hasNext())
    {
        if(it->current()->getName() == name)
        {
            delete it->current();
            delete it;
            directories.erase(it->at(i));
            return;
        }
        it->next();
        i++;
    }
    delete it;
    cout << "Directory not found" << endl;
}
Node* Directory::copy()
{
    Directory *newDir = new Directory(this->getName() + " copy");
    if(directories.size() > 0)
    {
        NodeIterator * it = directories[0]->createIterator();
        it->setVector(directories);
        while(it->hasNext())
        {
            newDir->addDirectory(it->current()->copy());
            it->next();
        }
        delete it;
    }
    if(files.size() > 0)
    {
        NodeIterator * it = files[0]->createIterator();
        it->setVector(files);
        while(it->hasNext())
        {
            newDir->addFile(it->current()->copy());
            it->next();
        }
        delete it;
    }
    return newDir;
}
bool Directory::isEmpty()
{
    return files.size() == 0 && directories.size() == 0;
}
bool Directory::listFiles()
{
    if (files.size() == 0)
    {
        cout << "No files in this directory" << endl;
        return false;
    }
    NodeIterator * it = files[0]->createIterator();
    it->setVector(files);
    cout<<"Files in "<<this->getName()<<":"<<endl;
    while(it->hasNext())
    {
        it->current()->listFiles();
        it->next();
    }
    delete it;
    return true;
}
bool Directory::listDirectories()
{
    if (directories.size() == 0)
    {
        cout << "No directories in this directory" << endl;
        return false;
    }
    NodeIterator * it = directories[0]->createIterator();
    it->setVector(directories);
    cout<<"Directories in "<<this->getName()<<":"<<endl;
    while(it->hasNext())
    {
        it->current()->listDirectories();
        it->next();
    }
    delete it;
    return true;
}
NodeIterator * Directory::createIterator()
{
    return new DirectoryIterator();
}
void Directory::showStructure()//depth first traversal
{
    cout << "Directory: " << this->getName() << endl;
    if(directories.size() > 0)
    {
        NodeIterator * it = directories[0]->createIterator();
        it->setVector(directories);
        while(it->hasNext())
        {
            it->current()->showStructure();
            it->next();
        }
        delete it;
    }
    if(files.size() > 0)
    {
        NodeIterator * it = files[0]->createIterator();
        it->setVector(files);
        while(it->hasNext())
        {
            it->current()->showStructure();
            it->next();
        }
        delete it;
    }
}
void Directory::showContents()//breadth first traversal
{
    this->listDirectories();
    this->listFiles();
    if(directories.size() > 0)
    {
        NodeIterator * it = directories[0]->createIterator();
        it->setVector(directories);
        while(it->current() != nullptr && it->next()->listDirectories()){
            
        }
        delete it;
    }
    if(files.size() > 0)
    {
        NodeIterator * it = files[0]->createIterator();
        it->setVector(files);
        while(it->current() != nullptr && it->next()->listFiles()){
            
        }
        delete it;
    }
}
