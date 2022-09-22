//Tayla Orsmond u21467456
#include "Directory.h"
#include "DirectoryIterator.h"
#include "File.h"
#include "FileIterator.h"
#include "Node.h"
#include "NodeIterator.h"
#include "Root.h"
#include "Observer.h"

using namespace std;
int main(){
    Root * root = new Root("root");
    Node * dir1 = new Directory("dir1");
    Node * dir2 = new Directory("dir2");
    Node * dir3 = new Directory("dir3");
    Node * dir4 = new Directory("dir4");

    Node * file1 = new File("file1", "file1 contents");
    Node * file2 = new File("file2", "file2 contents");
    Node * file3 = new File("file3", "file3 contents");
    Node * file4 = new File("file4", "file4 contents");

    Observer * obs1 = new Observer();
    Observer * obs2 = new Observer();
    Observer * obs3 = new Observer();
    Observer * obs4 = new Observer();

    root->attatch(obs1);
    root->attatch(obs2);
    dir1->attatch(obs2);
    dir2->attatch(obs3);
    dir3->attatch(obs4);
    dir4->attatch(obs4);
    file1->attatch(obs4);
    file2->attatch(obs4);
    file3->attatch(obs4);
    file4->attatch(obs4);

    root->addDirectory(dir1);
    root->addDirectory(dir2);
    dir2->addDirectory(dir3);
    dir3->addDirectory(dir4);
    dir4->addFile(file1);
    dir4->addFile(file2);
    dir2->addFile(file3);
    root->addFile(file4);
    file4->addFile(new File());
    file4->addDirectory(new Directory());

    

    cout<<endl;
    root->showStructure();
    root->showContents();
    file2->setName("file2 renamed");
    file2->setContents("file4 contents renamed with cos 214 !");

    cout<<"\n\n==========================Taking snapshot..."<<endl;
    root->takeSnapshot();
    cout<<"\n\n==========================Removing file4..."<<endl;
    root->removeFile("file4");
    cout<<"\n\n==========================Removing dir3..."<<endl;
    dir2->removeDirectory("dir3");
    cout<<endl;
    root->showStructure();
    root->showContents();
    cout<<"\n\n========================Restoring snapshot..."<<endl;
    root->restoreSnapshot();
    cout<<endl;
    root->showStructure();
    root->showContents();
    cout<<"\n\n========================Taking snapshot..."<<endl;
    root->takeSnapshot();
    cout<<"\n\n==========================Removing dir1 copy..."<<endl;
    root->removeDirectory("dir1 copy");
    cout<<"\n\n==========================Adding stuff..."<<endl;
    root->addFile(file1->copy());
    root->addDirectory(dir1->copy());
    cout<<"\n\n========================Taking snapshot..."<<endl;
    root->takeSnapshot();
    cout<<"\n\n========================Viewing snapshots..."<<endl;
    root->viewSnapshots();
    cout<<"\n\n========================Clearing snapshots..."<<endl;
    root->clearSnapshots();
    cout<<"\n\n========================Viewing snapshots..."<<endl;
    root->viewSnapshots();
    cout<<"\n\n========================Deleting root..."<<endl;

    delete root;
    delete obs1;
    delete obs2;
    delete obs3;
    delete obs4;
    return 0;
}