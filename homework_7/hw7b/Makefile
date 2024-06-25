homework7b: main.o functions.o
	gcc main.o functions.o -o homework7b

main.o: main.c
	gcc -ansi -pedantic-errors -Wall -c main.c

functions.o: functions.c
	gcc -ansi -pedantic-errors -Wall -c functions.c

clean:
	rm *.o homework7b
