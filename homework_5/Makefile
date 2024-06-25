homework5: driver.o iofunctions.o record.h iofunctions.h
	gcc -o homework5 driver.o iofunctions.o

iofunctions.o: iofunctions.c record.h
	gcc -ansi -pedantic-errors -Wall -c iofunctions.c

driver.o: driver.c record.h iofunctions.h
	gcc -ansi -pedantic-errors -Wall -c driver.c

clean:
	rm *.o homework5 
