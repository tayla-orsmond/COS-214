//Tayla Orsmond u21467456
#include "File.h"
using namespace std;
File::File(): Node("New File")
{
    this->contents = "";
    cout<<this->getName()<<" created"<<endl;
}
File::File(string name, string contents) : Node(name)
{
    this->contents = contents;
    cout<<this->getName()<<" created"<<endl;
}
File::~File()
{
    cout<<"File deleted."<<endl;
}
void File::addFile(File *node)
{
    cout << "Cannot add a file to a file" << endl;
    delete node;
    node = nullptr;
}
void File::addDirectory(Directory *node)
{
    cout << "Cannot add a directory to a file" << endl;
    delete node;
    node = nullptr;
}
void File::removeFile(std::string name)
{
    cout << "Cannot remove a file from a file"<< endl;
}
void File::removeDirectory(std::string name)
{
    cout << "Cannot remove a directory from a file" << endl;
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
    cout<<"File: "<<this->getName()<<endl;
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
    cout << this->getName() << ": " << this->getContents() << endl;
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
