//Tayla Orsmond u21467456
#include "Folder.h"
using namespace std;
Folder::Folder(): Node("New Folder")
{
    std::cout<<this->getName()<<" created"<<std::endl;
}
Folder::Folder(string name) : Node(name)
{
    std::cout<<this->getName()<<" created"<<std::endl;
}
Folder::~Folder()
{
    std::cout<<this->getName()<<" deleted"<<std::endl;
    for(int i = 0; i < this->files.size(); i++)
    {
        delete this->files[i];
    }
    for(int i = 0; i < this->folders.size(); i++)
    {
        delete this->folders[i];
    }
}
void Folder::addFile(Node *node)
{
    node->format += this->format + "\t";
    files.push_back(node);
}
void Folder::addFolder(Node * node)
{
    node->format += this->format + "\t";
    folders.push_back(node);
}
void Folder::removeFile(std::string name)
{
    if(files.size() == 0)
    {
        std::cout<<"No files to remove."<<std::endl;
        return;
    }
    for(int i = 0; i < files.size(); i++)
    {
        if(files[i]->getName() == name)
        {
            delete files[i];
            files.erase(files.begin() + i);
            return;
        }
    }
    std::cout<<"File not found."<<std::endl;
}
void Folder::removeFolder(std::string name)
{
    if(folders.size() == 0)
    {
        std::cout<<"No folders to remove."<<std::endl;
        return;
    }
    for(int i = 0; i < folders.size(); i++)
    {
        if(folders[i]->getName() == name)
        {
            delete folders[i];
            folders.erase(folders.begin() + i);
            return;
        }
    }
    std::cout << "Folder not found" << std::endl;
}
Node* Folder::copy()
{
    Folder *newDir = new Folder(this->getName() + " copy");
    for(int i = 0; i < this->files.size(); i++)
    {
        newDir->addFile(this->files[i]->copy());
    }
    for(int i = 0; i < this->folders.size(); i++)
    {
        newDir->addFolder(this->folders[i]->copy());
    }
    return newDir;
}
bool Folder::isEmpty()
{
    return files.size() == 0 && folders.size() == 0;
}
void Folder::listContents()
{
    std::cout<<this->format<<"["<<this->getName()<<std::endl;
    for(int i = 0; i < this->files.size(); i++)
    {
        this->files[i]->listContents();
    }
    for(int i = 0; i < this->folders.size(); i++)
    {
        this->folders[i]->listContents();
    }
    std::cout<<this->format<<"]"<<std::endl;
}