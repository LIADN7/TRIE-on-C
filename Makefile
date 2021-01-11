AR=ar
FLAGS= -Wall -g

all: frequency
frequency: frequency.o
	gcc $(FLAGS) -o frequency frequency.o
frequency.o: frequency.c
	gcc $(FLAGS) -c frequency.c

.PHONY: clean all

clean:
	rm -f *.o frequency
