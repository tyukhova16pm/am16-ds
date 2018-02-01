all: lab

lab: lab.o 
	gcc lab.o -o lab

lab.o: lab.c
	gcc -c lab.c

clean:
	rm -rf *.o lab
