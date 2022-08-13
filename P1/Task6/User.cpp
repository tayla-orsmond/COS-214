#include <iostream>
#include "User.h"

User::User(std::string username, std::string password) : _username(username), _password(password){
    std::cout << "User: I have been initialized with username " << this->_username 
    << " and a password of " << this->_password << "\n";
}

void User::SetPassword(std::string passw){
    std::cout << "User: Setting a new secure password.\n";
    this->_password = passw;
    std::cout << "User: My password has been changed to: " << this->_password << "\n";
}

//Save password memento
AuditableSnapshot * User::Save(){
    std::cout << "User: Saving password...\n";
    return new Snapshot(this->_username, this->_password);
}

//Restore from prev password
void User::Restore(AuditableSnapshot *memento) {
    this->_password = memento->state();
    std::cout << "User: My password has changed to: " << this->_password << "\n";
}
void User::ShowHistory(std::vector<AuditableSnapshot *> m){
    std::cout<<"User: Password History: \n";
    std::vector<AuditableSnapshot *>::iterator i;
    for(i = m.begin(); i != m.end(); i++){
        std::cout<<"Time: "<<(*i)->date()<<" State: "<<(*i)->state()<<std::endl;
    }
}
