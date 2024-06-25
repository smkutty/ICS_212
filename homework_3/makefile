
hw3b: database.o user_interface.o 
	gcc database.o user_interface.o -o hw3b

database.o: database.c
	gcc -ansi -pedantic-errors -Wall -c database.c

user_interface.o: user_interface.c
	gcc -ansi -pedantic-errors -Wall -c user_interface.c

clean:
	rm *.o out


