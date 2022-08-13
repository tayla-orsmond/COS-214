#ifndef UMANAGER_H
#define UMANAGER_H
#include <vector>
#include "Snapshot.h"
//Tayla Orsmond u21467456

//This class should be called Store as it doesn't really manage the user but stores mementos (caretaker)
class UserManager {
    private:
    std::vector<AuditableSnapshot *> mementos_;
    public:
    UserManager();
    void Backup(AuditableSnapshot *);
    AuditableSnapshot * Undo();
    std::vector<AuditableSnapshot *> ShowHistory();
};

#endif