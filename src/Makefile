all: number main regex clean

main: main.cpp number
	g++ main.cpp Fraction.o Integer.o -o main

number: Number.h Integer.cpp Fraction.cpp Log.cpp Power.cpp Polynomial.cpp Irrational.cpp Operations.h Operations.cpp Power.cpp
	g++ -c Number.h Integer.cpp Fraction.cpp Log.cpp Power.cpp Polynomial.cpp Irrational.cpp Operations.h Operations.cpp

regex: Regex.cpp
	g++ -o regex Regex.cpp Fraction.o Integer.o -lpcrecpp

clean: 
	\rm -rf *.o *.gch

