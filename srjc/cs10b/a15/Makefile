a15_2.out: a15_2.o mystring.o
	g++ a15_2.o mystring.o -o a15_2.out

a15_2.o: a15_2.cpp mystring.h
	g++ -c a15_2.cpp -o a15_2.o

mystring.o: mystring.cpp mystring.h
	g++ -c mystring.cpp -o mystring.o

run: a15_2.out
	./a15_2.out

clean:
	rm -f *.o *.out