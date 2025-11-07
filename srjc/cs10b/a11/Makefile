main.out: main.o mystring.o
	g++ main.o mystring.o -o main.out

main.o: main.cpp mystring.h
	g++ -c main.cpp -o main.o

mystring.o: mystring.cpp mystring.h
	g++ -c mystring.cpp -o mystring.o

run: main.out
	./main.out

clean:
	rm -f *.o *.out