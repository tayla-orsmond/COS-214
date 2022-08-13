#ifndef SNAP_H
#define SNAP_H
#include "AuditableSnapshot.h"
//Tayla Orsmond u21467456
class User;

class Snapshot: public AuditableSnapshot{
    private:   
    Snapshot(std::string, std::string);
    std::string GetUsername() const;
    std::string date() const;
    std::string state() const;

    std::string _username;
    std::string _state;
    std::string _date;
    friend class User;
};

#endif