all: number main clean

main: main.cpp
	g++ main.cpp -o main -std=c++0x

number: Number.h Integer.cpp Fraction.cpp Log.cpp
	g++ -c Number.h Integer.cpp Fraction.cpp Log.cpp

clean: 
	\rm -rf *.o *.gch

