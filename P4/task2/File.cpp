//Tayla Orsmond u21467456
#include "File.h"
using namespace std;

File::File(): Node("New File")
{
    this->contents = "";
    std::cout<<this->getName()<<" created"<<std::endl;
}
File::File( std::string name, std::string contents) : Node(name)
{
    this->contents = contents;
    std::cout<<this->getName()<<" created"<<std::endl;
}
File::~File()
{
    std::cout<<this->getName()<<" deleted"<<std::endl;
}
void File::addFile(Node *node)
{
    std::cout << "Cannot add a file to a file" << std::endl;
    delete node;
    node = nullptr;
}
void File::addFolder(Node *node)
{
    std::cout << "Cannot add a folder to a file" << std::endl;
    delete node;
    node = nullptr;
}
void File::removeFile(std::string name)
{
    std::cout << "Cannot remove a file from a file"<< std::endl;
}
void File::removeFolder(std::string name)
{
    std::cout << "Cannot remove a folder from a file" << std::endl;
}
Node* File::copy()
{
    return new File(this->getName() + " copy", this->getContents());
}
bool File::isEmpty()
{
    if(contents == "")
    {
        return true;
    }
    return false;
}
void File::listContents()
{
    std::cout<<this->format<<" >"<< this->getName() << " :\"" << this->getContents() <<"\"\n";
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
