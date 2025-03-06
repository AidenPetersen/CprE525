CC = gcc
FFLAGS = -O3 -Wall -std=c99
LFLAGS = -lm
OBJECTS = main.o matrix.o eigen.o

.PHONY : clean

main: $(OBJECTS)
	$(CC) -lm $(OBJECTS) -o main

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean :
	rm -f $(OBJECTS) main
