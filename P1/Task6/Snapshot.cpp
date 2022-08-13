#include <time.h>
#include "Snapshot.h"

Snapshot::Snapshot(std::string user, std::string passw): _username(user), _state(passw){
    this->_date = "Just now";
}
std::string Snapshot::GetUsername() const{
    return this->_username;
}
std::string Snapshot::date() const{
    return this->_date;
}
std::string Snapshot::state() const{
    return this->_state;
}