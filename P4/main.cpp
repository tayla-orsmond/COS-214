//Tayla Orsmond u21467456
#include "Directory.h"
#include "DirectoryIterator.h"
#include "File.h"
#include "FileIterator.h"
#include "Node.h"
#include "NodeIterator.h"

using namespace std;
int main(){
    Node * root = new Directory("root");
    Node * dir1 = new Directory("dir1");
    Node * dir2 = new Directory("dir2");
    Node * dir3 = new Directory("dir3");
    Node * dir4 = new Directory("dir4");
    root->addDirectory(dir1);
    root->addDirectory(dir2);
    dir2->addDirectory(dir3);
    dir3->addDirectory(dir4);
    Node * file1 = new File("file1", "This is file 1");
    Node * file2 = new File("file2", "This is file 2");
    Node * file3 = new File("file3", "This is file 3");
    Node * file4 = new File("file4", "This is file 4");
    root->addFile(file1);
    root->addFile(file2);
    file1->addFile(new File());
    file1->addDirectory(new Directory());
    dir1->addFile(file3);
    dir2->addFile(file4);
    cout<<"\nRoot directory: "<<root->getName()<<endl;
    root->listFiles();
    root->listDirectories();
    cout<<"Removing file1..."<<endl;
    root->removeFile("file1");
    cout<<"Removing dir4..."<<endl;
    root->removeDirectory("dir4");
    cout<<"Structure:"<<endl;
    root->showStructure();
    cout<<"Contents:"<<endl;
    root->showContents();
    delete root;
    return 0;
}