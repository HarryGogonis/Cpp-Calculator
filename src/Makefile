all: number main clean

main: main.cpp
	g++ main.cpp -o main -std=c++0x

number: Number.h Integer.cpp Fraction.cpp
	g++ -c Number.h Integer.cpp Fraction.cpp

clean: 
	\rm -rf *.o *.gch

