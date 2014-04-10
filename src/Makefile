all: number main clean

main: main.cpp number
	g++ main.cpp Integer.o Fraction.o Log.o -o main

number: Number.h Integer.cpp Fraction.cpp Log.cpp Operations.h Operations.cpp Power.cpp
	g++ -c Number.h Integer.cpp Fraction.cpp Log.cpp Operations.h Operations.cpp Power.cpp

clean: 
	\rm -rf *.o *.gch

