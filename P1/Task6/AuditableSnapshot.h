#ifndef AUDITSNAP_H
#define AUDITSNAP_H
#include <string>
//Tayla Orsmond u21467456

class AuditableSnapshot {
    public:
    virtual std::string GetUsername() const = 0;
    virtual std::string date() const = 0;
    virtual std::string state() const = 0;
};

#endif