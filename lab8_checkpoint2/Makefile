CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o my_string.o generic_vector.o evil_tree.o
OBJECTS2 = my_string.o test_def.o unit_test.o

all: string_driver unit_test

string_driver: $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o string_driver 
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c my_string.h generic.h	generic_vector.c evil_tree.h evil_tree.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
	$(CC) $(CFALGS) -c generic_vector.c -o generic_vector.o
	$(CC) $(CFLAGS) -c evil_tree.c -o evil_tree.o

unit_test: $(OBJECTS2)
	$(CC) $(CFLAGS) -o unit_test $(OBJECTS2)
test_def.o: test_def.c
	$(CC) $(CFALGS) -c test_def.c -o test_def.o
unit_test.o: unit_test.c unit_test.h
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o


clean:
	rm string_driver $(OBJECTS) $(OBJECTS2) unit_test



