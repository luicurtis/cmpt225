all: stack

stack: Stack.o StkTest.o
	g++ -Wall -o stack Stack.o StkTest.o

STACK.o: StkTest.cpp Stack.h
	g++ -Wall -c StkTest.cpp

Stack.o: Stack.h Stack.cpp
	g++ -Wall -c Stack.cpp

clean:
	rm -f wi *.o