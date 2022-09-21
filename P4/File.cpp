//Tayla Orsmond u21467456
#include "File.h"

File::File(): Node("New File")
{
    this->contents = "";
    std::cout<<this->getName()<<" created"<<std::endl;
}
File::File(string name, string contents) : Node(name)
{
    this->contents = contents;
    std::cout<<this->getName()<<" created"<<std::endl;
}
File::~File()
{
    std::cout<<"File deleted."<<std::endl;
}
void File::addFile(Node *node)
{
    std::cout << "Cannot add a file to a file" << std::endl;
    delete node;
    node = nullptr;
}
void File::addDirectory(Node *node)
{
    std::cout << "Cannot add a directory to a file" << std::endl;
    delete node;
    node = nullptr;
}
void File::removeFile(std::string name)
{
    std::cout << "Cannot remove a file from a file"<< std::endl;
}
void File::removeDirectory(std::string name)
{
    std::cout << "Cannot remove a directory from a file" << std::endl;
}
Node* File::copy()
{
    return new File(this->getName() + " copy", this->getContents());
}
bool File::isEmpty()
{
    return false;
}
bool File::listFiles()
{
    std::cout<<"File: "<<this->getName()<<std::endl;
    return true;//no files in a file
}
bool File::listDirectories()
{
    return true;//no directories in a file
}
NodeIterator * File::createIterator()
{
    return new FileIterator();
}
void File::showStructure()//depth first traversal
{
    while(!this->listFiles()){};
}
void File::showContents()//breadth first traversal
{
    std::cout << this->getName() << ": " << this->getContents() << std::endl;
}
//getters and setters
string File::getContents()
{
    return contents;
}
void File::setContents(string contents)
{
    this->contents = contents;
}
