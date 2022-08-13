main: main.o
	g++ -o main *.o 

main.o: main.cpp 
	g++ -c *.cpp

Enemy.o: Enemy.h Enemy.cpp
	g++ -c Enemy.cpp

EnemyFactory.o: EnemyFactory.h EnemyFactory.cpp
	g++ -c EnemyFactory.cpp

SquadMember.o: SquadMember.h SquadMember.cpp
	g++ -c SquadMember.cpp

Snake.o: Snake.h Snake.cpp
	g++ -c Snake.cpp

SnakeFactory.o: SnakeFactory.h SnakeFactory.cpp
	g++ -c SnakeFactory.cpp

Gorilla.o: Gorilla.h Gorilla.cpp
	g++ -c Gorilla.cpp

GorillaFactory.o: GorillaFactory.h GorillaFactory.cpp
	g++ -c GorillaFactory.cpp

Jaguar.o: Jaguar.h Jaguar.cpp
	g++ -c Jaguar.cpp

JaguarFactory.o: JaguarFactory.h JaguarFactory.cpp
	g++ -c JaguarFactory.cpp

Cannibal.o: Cannibal.h Cannibal.cpp
	g++ -c Cannibal.cpp

CannibalFactory.o: CannibalFactory.h CannibalFactory.cpp
	g++ -c CannibalFactory.cpp

run:
	make
	./main

clean: 
	rm *.o main

