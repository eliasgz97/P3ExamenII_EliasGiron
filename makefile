run: Main.o Militar.o NodoArbol.o
	g++ Main.o Militar.o NodoArbol.o -lncurses -o run
Main.o: Main.cpp Militar.h NodoArbol.h 
	g++ -c Main.cpp
Militar.o: Militar.h Militar.cpp
	g++ -c Militar.cpp
NodoArbol.o: NodoArbol.h NodoArbol.cpp
	g++ -c NodoArbol.cpp
