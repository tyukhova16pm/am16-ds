CC=gcc
FLAGS=-std=c99

all: lab4
lab4: lab4.o huff.o
	$(CC) $(FLAGS) lab4.o huff.o -o lab4

lab4.o: lab4.c
	$(CC) $(FLAGS) -c lab4.c

huff.o: huff.c
	$(CC) $(FLAGS) -c huff.c

clean:
	rm -rf *.o lab4 dl

debug:
	$(CC) $(FLAGS) -g lab4.c huff.c -o dl 
