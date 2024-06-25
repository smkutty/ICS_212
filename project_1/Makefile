
all: project project_debug

project: user_interface.o llist.o
	g++ user_interface.o llist.o -o project

user_interface.o: user_interface.cpp
	g++ -ansi -pedantic-errors -Wall -g -c user_interface.cpp

llist.o: llist.cpp
	g++ -ansi -pedantic-errors -Wall -g -c llist.cpp

project_debug: ui_debug.o llist_debug.o
	g++ user_interface.o llist.o -o project_debug

ui_debug.o: user_interface.cpp
	g++ -D DEBUGMODE -ansi -pedantic-errors -Wall -c user_interface.cpp

llist_debug.o: llist.cpp
	g++ -D DEBUGMODE -ansi -pedantic-errors -Wall -c llist.cpp

clean:
	rm *.o project project_debug
