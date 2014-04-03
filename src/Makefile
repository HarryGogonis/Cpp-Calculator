all: number main clean

main: main.cpp
	g++ main.cpp -o main -std=c++0x

number: Number.h Integer.h
	g++ -c Number.h Integer.h

clean: 
	\rm -rf *.o *.gch

