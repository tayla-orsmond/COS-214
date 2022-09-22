//Tayla Orsmond u21467456
#include "File.h"
#include "Folder.h"
using namespace std;
int main(){
    Node * root = new Folder("root");
    Node * dir1 = new Folder("dir1");
    Node * dir2 = new Folder("dir2");
    Node * dir3 = new Folder("dir3");
    Node * dir4 = new Folder("dir4");
    root->addFolder(dir1);
    root->addFolder(dir2);
    dir2->addFolder(dir3);
    dir3->addFolder(dir4);
    Node * file1 = new File("file1", "This is file 1");
    Node * file2 = new File("file2", "This is file 2");
    Node * file3 = new File("file3", "This is file 3");
    Node * file4 = new File("file4", "This is file 4");
    root->addFile(file1);
    root->addFile(file2);
    file1->addFile(new File());
    file1->addFolder(new Folder());
    dir1->addFile(file3);
    dir2->addFile(file4);
    cout<<"\nRoot Folder: "<<root->getName()<<endl;
    root->listContents();
    cout<<"Removing file1..."<<endl;
    root->removeFile("file1");
    cout<<"Removing dir4..."<<endl;
    root->removeFolder("dir4");
    cout<<"Contents:"<<endl;
    root->listContents();
    cout<<"\n\nMaking copy of root..."<<endl;
    Node * rootCopy = root->copy();
    cout<<"Removing dir2..."<<endl;
    rootCopy->removeFolder("dir2 copy");
    cout<<"Contents:"<<endl;
    rootCopy->listContents();
    delete root;
    delete rootCopy;
    return 0;
}