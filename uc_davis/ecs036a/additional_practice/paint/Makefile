paint.out: paint.o canvas.o paint_functions.o
	gcc -g -Wall -Werror -o paint.out paint.o canvas.o paint_functions.o

paint.o: paint.c canvas.h
	gcc -g -Wall -Werror -c paint.c

canvas.o: canvas.c canvas.h
	gcc -g -Wall -Werror -c canvas.c

paint_functions.o: paint_functions.c paint_functions.h
	gcc -g -Wall -Werror -c paint_functions.c

run: paint.out
	./paint.out

debug: paint.out
	gdb --tui ./paint.out

clean:
	rm -fr *.o *.out