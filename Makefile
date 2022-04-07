all: run

run: App
	./App

.PHONY: all run

App: main.o needed.o
	gcc main.o needed.o -o App
	rm -rf *.o

main.o: main.c
	gcc -c main.c -o main.o

needed.o:
	gcc -c needed.c -o needed.o