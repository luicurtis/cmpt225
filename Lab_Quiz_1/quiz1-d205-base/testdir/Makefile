
x:	main.o LL.o
	g++ -o x LL.o main.o

main.o:	main.cpp Complex.h LL.h
	g++ -c main.cpp

LL.o:	LL.cpp LL.h
	g++ -c LL.cpp

clean:	
	rm -f *.o x *.out *.tmp
