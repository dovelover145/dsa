fractionclient.out: fractionclient.o fraction.o
	g++ fractionclient.o fraction.o -o fractionclient.out

fractionclient.o: fractionclient.cpp fraction.h
	g++ -c fractionclient.cpp -o fractionclient.o

fraction.o: fraction.cpp fraction.h
	g++ -c fraction.cpp -o fraction.o

run: fractionclient.out
	./fractionclient.out

clean:
	rm -f *.o *.out