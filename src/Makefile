all: number main clean

main: main.cpp number
	g++ -I boost/ main.cpp Integer.o Fraction.o Log.o -o main

<<<<<<< HEAD
number: Number.h Integer.cpp Fraction.cpp
=======
number: Number.h Integer.cpp Fraction.cpp Log.cpp
>>>>>>> b0fc416e898447c8a53dcdbd9a2388c20c789ceb
	g++ -c Number.h Integer.cpp Fraction.cpp Log.cpp

clean: 
	\rm -rf *.o *.gch

