homework7a: driver.o paint.o
	gcc driver.o paint.o -o homework7a

paint.o: paint.c
	gcc -c -ansi -pedantic-errors -Wall paint.c

driver.o: driver.c
	gcc -c -ansi -pedantic-errors -Wall driver.c

clean:
	rm *.o homework7a
