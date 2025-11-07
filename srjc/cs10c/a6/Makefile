main.out: main.o sequence.o
	g++ main.o sequence.o -o main.out

main.o: main.cpp sequence.h
	g++ -c main.cpp -o main.o

sequence.o: sequence.cpp sequence.h
	g++ -c sequence.cpp -o sequence.o

run: main.out
	./main.out

clean:
	rm -f *.o *.out