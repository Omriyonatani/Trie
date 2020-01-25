CC = gcc
AR = ar -rcs
FLAGS = -Wall

all: frequency

frequency: main.o trie.o 
	$(CC) $(FLAGS) main.o trie.o -o frequency
main.o: main.c trie.o
	$(CC) $(FLAGS) -c main.c 
trie.o: trie.c
	$(CC) $(FLAGS) -c trie.c



.PHONY: clean all

clean:
	rm -f *.o *.a *.so out frequency