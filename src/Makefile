all: number main clean

main: main.cpp number
	g++ -I boost/ main.cpp Integer.o Fraction.o Log.o -o main

number: Number.h Integer.cpp Fraction.cpp Log.cpp Operations.h Operations.cpp
	g++ -c Number.h Integer.cpp Fraction.cpp Log.cpp Operations.h Operations.cpp

clean: 
	\rm -rf *.o *.gch

