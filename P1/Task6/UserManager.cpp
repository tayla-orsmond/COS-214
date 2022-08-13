#include <iostream>
#include "UserManager.h"
//Tayla Orsmond u21467456

UserManager::UserManager(){
    std::cout<<"User Manager: Created storage for mementos.\n";
}
//Save Memento
void UserManager::Backup(AuditableSnapshot * memento){
    std::cout << "UserManager: Saving User's state (password)...\n";
    this->mementos_.push_back(memento);
}
//Rollback memento
AuditableSnapshot * UserManager::Undo(){
    std::cout<<"User Manager: Rolling back...\n";
    if(this->mementos_.size() > 0){
        AuditableSnapshot * memento = this->mementos_.back();
        this->mementos_.pop_back();
        return memento;
    }
    return NULL;
}
std::vector<AuditableSnapshot *> UserManager::ShowHistory(){
    return this->mementos_;
}
