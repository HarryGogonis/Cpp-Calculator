all: number main clean

main: main.cpp
	g++ main.cpp -o main -std=c++0x

number: Number.h Integer.h Integer.cpp Fraction.h Fraction.cpp
	g++ -c Number.h Integer.h Integer.cpp Fraction.h Fraction.cpp

clean: 
	\rm -rf *.o *.gch

