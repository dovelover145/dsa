main.out: main.o PrecondViolatedExcep.o
	g++ main.o PrecondViolatedExcep.o -o main.out

main.o: main.cpp PrecondViolatedExcep.h
	g++ -c main.cpp -o main.o

PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -c PrecondViolatedExcep.cpp -o PrecondViolatedExcep.o

run: main.out
	./main.out

clean:
	rm -f *.o *.out