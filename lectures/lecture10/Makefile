INC=.
CFLAGS=-lm -I$(INC)
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

all: quad

quad: $(OBJS)
	gcc $(CFLAGS) -o quad $(OBJS)

%.o: %.c
	gcc -c $(CFLAGS) $< -o $@
