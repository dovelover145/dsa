a13.out: creature.o human.o elf.o demon.o cyberdemon.o balrog.o a13.o
	g++ creature.o human.o elf.o demon.o cyberdemon.o balrog.o a13.o -o a13.out

a13.o: a13.cpp creature.h human.h elf.h demon.h cyberdemon.h balrog.h
	g++ -c a13.cpp -o a13.o

balrog.o: balrog.cpp balrog.h demon.h
	g++ -c balrog.cpp -o balrog.o

cyberdemon.o: cyberdemon.cpp cyberdemon.h demon.h
	g++ -c cyberdemon.cpp -o cyberdemon.o

demon.o: demon.cpp demon.h creature.h
	g++ -c demon.cpp -o demon.o

elf.o: elf.cpp elf.h creature.h
	g++ -c elf.cpp -o elf.o

human.o: human.cpp human.h creature.h
	g++ -c human.cpp -o human.o

creature.o: creature.cpp creature.h
	g++ -c creature.cpp -o creature.o

run: a13.out
	./a13.out

clean:
	rm -f *.o *.out