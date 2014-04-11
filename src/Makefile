all: number main clean

main: main.cpp number
	g++ main.cpp *.o -o main

number: Number.h Integer.cpp Fraction.cpp Log.cpp Power.cpp Polynomial.cpp Irrational.cpp Operations.h Operations.cpp Power.cpp
	g++ -c Number.h Integer.cpp Fraction.cpp Log.cpp Power.cpp Polynomial.cpp Irrational.cpp Operations.h Operations.cpp

clean: 
	\rm -rf *.o *.gch

