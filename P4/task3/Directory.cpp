//Tayla Orsmond u21467456
#include "Directory.h"
using namespace std;
Directory::Directory(): Node("New Directory")
{
    std::cout<<this->getName()<<" created"<<std::endl;
}
Directory::Directory(string name) : Node(name)
{
    std::cout<<this->getName()<<" created"<<std::endl;
}
Directory::~Directory()
{
    std::cout<<this->getName()<<" deleted"<<std::endl;
    for(int i = 0; i < this->files.size(); i++)
    {
        delete this->files[i];
    }
    for(int i = 0; i < this->directories.size(); i++)
    {
        delete this->directories[i];
    }
}
void Directory::addFile(Node *node)
{
    node->format += this->format + "\t";
    files.push_back(node);
}
void Directory::addDirectory(Node * node)
{
    node->format += this->format + "\t";
    directories.push_back(node);
}
void Directory::removeFile(std::string name)
{
    if(files.size() == 0)
    {
        std::cout<<"No files to remove."<<std::endl;
        return;
    }
    NodeIterator * it = files[0]->createIterator();
    it->setVector(files);
    int i = 0;
    do{
        if(it->current()->getName() == name)
        {
            delete it->current();
            files.erase(it->at(i));
            delete it;
            return;
        }
        it->next();
        i++;
    }while(it->hasNext());
    
    delete it;
    std::cout<<"File not found."<<std::endl;
}
void Directory::removeDirectory(std::string name)
{
    if(directories.size() == 0)
    {
        std::cout<<"No directories to remove."<<std::endl;
        return;
    }
    NodeIterator * it = directories[0]->createIterator();
    it->setVector(directories);
    int i = 0;
    do{
        if(it->current()->getName() == name)
        {
            delete it->current();
            directories.erase(it->at(i));
            delete it;
            return;
        }
        it->next();
        i++;
    }while(it->hasNext());

    delete it;
    std::cout << "Directory not found" << std::endl;
}
Node* Directory::copy()
{
    Directory *newDir = new Directory(this->getName() + " copy");
    if(directories.size() > 0)
    {
        NodeIterator * it = directories[0]->createIterator();
        it->setVector(directories); 
        do{
            newDir->addDirectory(it->current()->copy());
            it->next();
        }while(it->hasNext());
        delete it;
    }
    if(files.size() > 0)
    {
        NodeIterator * it = files[0]->createIterator();
        it->setVector(files);
        do{
            newDir->addFile(it->current()->copy());
            it->next();
        }while(it->hasNext());
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
    std::cout<<this->format<<"[Files in "<<this->getName()<<":"<<std::endl;
    if(files.size() == 0)
    {
        std::cout<<this->format<< "\tNo files in this directory]" << std::endl;
        return true;
    }
    NodeIterator * it = files[0]->createIterator();
    it->setVector(files);
    do{
        it->current()->listFiles();
        it->next();
    }while(it->hasNext());
    delete it;
    std::cout<<this->format<<"]"<<std::endl;
    return false;
}
bool Directory::listDirectories()
{
    std::cout<<this->format<<"[Directories in "<<this->getName()<<":"<<std::endl;
    if(directories.size() == 0)
    {
        std::cout<<this->format<< "\tNo directories in this directory]" << std::endl;
        return true;
    }
    NodeIterator * it = this->createIterator();
    it->setVector(directories);
    do{
        std::cout<<this->format<<"> Directory:"<<it->current()->getName()<<std::endl;
        it->next();
    }while(it->hasNext());
    delete it;
    std::cout<<this->format<<"]"<<std::endl;
    return false;
}
NodeIterator * Directory::createIterator()
{
    return new DirectoryIterator();
}
void Directory::showStructure()//depth first traversal
{
    std::cout<<this->format<< "[Directory: " << this->getName() << std::endl;
    if(directories.size() > 0)
    {
        NodeIterator * it = this->createIterator();
        it->setVector(directories);
        do{
            it->current()->showStructure();
            it->next();
        }while(it->hasNext());
        delete it;
    }
    if(files.size() > 0)
    {
        NodeIterator * it = files[0]->createIterator();
        it->setVector(files);
        do{
            it->current()->showStructure();
            it->next();
        }while(it->hasNext());
        delete it;
    }
    std::cout<<this->format<<"]"<<std::endl;
}
void Directory::showContents()//breadth first traversal
{
    this->listFiles();
    if(files.size() > 0)
    {
        NodeIterator * it = files[0]->createIterator();
        it->setVector(files);
        do{
            it->current()->showContents();
            it->next();
        }while(it->hasNext());
        delete it;
    }
    this->listDirectories();
    if(directories.size() > 0)
    {
        NodeIterator * it = directories[0]->createIterator();
        it->setVector(directories);
        do{
            it->current()->showContents();
            it->next();
        }while(it->hasNext());
        delete it;
    }
}
