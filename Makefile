all: run

run: App
	./App

.PHONY: all run

App: main.o etudiant.o fonction.o
	gcc main.o etudiant.o fonction.o -o App
	rm -rf *.o

main.o: main.c
	gcc -c main.c -o main.o

fonction.o: fonction.c
	gcc -c fonction.c -o fonction.o

etudiant.o:
	gcc -c etudiant.c -o etudiant.o

clean:
	rm -rf *.o