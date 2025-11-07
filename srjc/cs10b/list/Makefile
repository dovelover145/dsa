client.out: client.o simplelist.o
	g++ client.o simplelist.o -o client.out

client.o: client.cpp simplelist.h
	g++ -c client.cpp -o client.o

simplelist.o: simplelist.cpp simplelist.h
	g++ -c simplelist.cpp -o simplelist.o

run: client.out
	./client.out

clean:
	rm -f *.o *.out