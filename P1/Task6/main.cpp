#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "User.h"
#include "UserManager.h"
//Tayla Orsmond u21467456
void Run();

int main() {
  std::srand(static_cast<unsigned int>(time(NULL)));
  Run();
  return 0;
}

void Run() {
  User *user = new User("username", "mysecretpassword");
  UserManager *userManager = new UserManager();
  userManager->Backup(user->Save());
  user->SetPassword("pa$$w0rd");

  userManager->Backup(user->Save());
  user->SetPassword("5t@rw@r5");

  userManager->Backup(user->Save());
  user->SetPassword("bigB@ng");
  std::cout<<std::endl;

  user->ShowHistory(userManager->ShowHistory());

  std::cout << "\nClient: Now, let's rollback!\n\n";
  user->Restore(userManager->Undo());
  std::cout << "\nClient: Once more!\n\n";
  user->Restore(userManager->Undo());

  delete user;
  delete userManager;
}

