 # This is the make file for the Floating Point Unit project of VLSI Design
all: main

main: main.o 
	g++ -std=c++11 main.cpp calculation.cpp inputparser.cpp -o floatingPoint
	
clean:
	rm *o solarPanel
