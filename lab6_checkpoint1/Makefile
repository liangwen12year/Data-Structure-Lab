CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = my_string.o unit_test.o test_def.o

unit_test: $(OBJECTS) 
	$(CC) $(CFLAGS) $(OBJECTS) -o unit_test
test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o
unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
my_string.o: my_string.c my_string.h generic.h
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
clean:
	rm unit_test $(OBJECTS)



