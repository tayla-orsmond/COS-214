#ifndef USER_H
#define USER_H
#include <vector>
#include<string>
#include "Snapshot.h"
//Tayla Orsmond u21467456

class User {
  private:
  std::string _username;
  std::string _password;
  
  public:
  User(std::string, std::string);
  void SetPassword(std::string);
  AuditableSnapshot *Save();
  void Restore(AuditableSnapshot *);
  void ShowHistory(std::vector<AuditableSnapshot *>);
};

#endif