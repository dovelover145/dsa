binarytree-client.out: binarytree-client.o binarytree.o
	g++ binarytree-client.o binarytree.o -o binarytree-client.out

binarytree-client.o: binarytree-client.cpp binarytree.h
	g++ -c binarytree-client.cpp -o binarytree-client.o

binarytree.o: binarytree.cpp binarytree.h LL.h
	g++ -c binarytree.cpp -o binarytree.o

run: binarytree-client.out
	./binarytree-client.out

clean:
	rm -f *.o *.out