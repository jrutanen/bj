bj: main.o Deck.o 
	g++ -o bj main.o Deck.o 

main.o : main.cpp Card.h
	g++ -c main.cpp

Deck.o : Deck.cpp Deck.h Card.h
	g++ -c Deck.cpp
