hw9: hw9.class hw9.h libhw9.so
	java -Djava.library.path=. hw9

hw9.class: hw9.java
	javac hw9.java

hw9.h: hw9.java
	javah -jni hw9

libhw9.so: hw9.o
	gcc -I/usr/java/jdk1.8.0_131/include -I/usr/java/jdk1.8.0_131/include/linux -shared -o libhw9.so hw9.o

hw9.o: hw9.c hw9.h
	gcc -c -fPIC -I/usr/java/jdk1.8.0_131/include -I/usr/java/jdk1.8.0_131/include/linux hw9.c


clean:
	rm *.o *.h *.class
