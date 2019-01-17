CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o my_string.o generic_vector.o

string_driver: $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o string_driver 
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c my_string.h generic.h	generic_vector.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
	$(CC) $(CFALGS) -c generic_vector.c -o generic_vector.o
clean:
	rm string_driver $(OBJECTS) *.o



