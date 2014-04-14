all: number main regex clean

main: main.cpp number
	g++ -o main main.cpp Fraction.o Integer.o Operations.o Log.o Power.o -lpcrecpp

number: Number.h Integer.cpp Fraction.cpp Log.cpp Power.cpp Polynomial.cpp Irrational.cpp Operations.h Operations.cpp Power.cpp
	g++ -c Number.h Integer.cpp Fraction.cpp Log.cpp Power.cpp Polynomial.cpp Irrational.cpp Operations.h Operations.cpp

clean: 
	\rm -rf *.o *.gch

