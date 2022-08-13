main: main.o User.o UserManager.o Snapshot.o AuditableSnapshot.o
	g++ -o main main.o User.o UserManager.o Snapshot.o AuditableSnapshot.o

main.o: main.cpp 
	g++ -c main.cpp

User.o: User.h User.cpp
	g++ -c User.cpp

UserManager.o: UserManager.h UserManager.cpp
	g++ -c UserManager.cpp

Snapshot.o: Snapshot.h Snapshot.cpp 
	g++ -c Snapshot.cpp

AuditableSnapshot.o: AuditableSnapshot.h AuditableSnapshot.cpp
	g++ -c AuditableSnapshot.cpp
run:
	make
	./main

clean: *.o
	rm *.o main

