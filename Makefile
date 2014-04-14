all: number main clean

main: src/main.cpp number
	g++ -o Calc src/main.cpp Fraction.o Integer.o Operations.o Log.o Power.o Polynomial.o Irrational.o -lpcrecpp

number: src/Number.h src/Integer.cpp src/Fraction.cpp src/Log.cpp src/Power.cpp src/Polynomial.cpp src/Irrational.cpp src/Operations.h src/Operations.cpp src/Power.cpp
	g++ -c src/Number.h src/Integer.cpp src/Fraction.cpp src/Log.cpp src/Power.cpp src/Polynomial.cpp src/Irrational.cpp src/Operations.h src/Operations.cpp

clean: 
	\rm -rf *.o *.gch

