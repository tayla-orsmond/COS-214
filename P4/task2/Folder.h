//Tayla Orsmond u21467456
//The Folder class
//Inherits from Node
//The Folder class is used to specify a Folder
//The Folder has a list of files and directories
//The Folder has a showStructure() method
//The Folder has a showContents() method
//The Folder has a copy() method
//The Folder has an isEmpty() method

#include "Node.h"
#include <iostream>
#include <string>
#include <vector>

class Folder : public Node
{
    public:
        Folder();
        Folder(std::string name);
        ~Folder();
        void addFile(Node *node);
        void addFolder(Node *node);
        void removeFile(std::string name);
        void removeFolder(std::string name);
        Node* copy();
        bool isEmpty();
        void listContents();
    private:
        std::vector<Node *> files;
        std::vector<Node *> folders;
};