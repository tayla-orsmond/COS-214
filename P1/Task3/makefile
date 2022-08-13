main: main.o 
	g++ -o main main.o 

main.o: main.cpp Calculator.h Calculator.cpp
	g++ -c -std=c++98 main.cpp

run:
	make
	./main

clean: *.o
	rm *.o main
