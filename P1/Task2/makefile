main: main.o ClassA.o ClassB.o ClassC.o ClassD.o ClassE.o 
	g++ -o main main.o ClassA.o ClassB.o ClassC.o ClassD.o ClassE.o 

main.o: main.cpp 
	g++ -c -std=c++98 main.cpp

ClassA.o: ClassA.cpp ClassA.h
	g++ -c -std=c++98 ClassA.cpp

ClasB.o: ClassB.cpp ClassB.h
	g++ -c -std=c++98 ClassB.cpp

ClassC.o: ClassC.cpp ClassC.h
	g++ -c -std=c++98 ClassC.cpp

ClassD.o: ClassD.cpp ClassD.h
	g++ -c -std=c++98 ClassD.cpp

ClassE.o: ClassE.cpp ClassE.h
	g++ -c -std=c++98 ClassE.cpp
	
run:
	make
	./main

clean: *.o
	rm *.o main
