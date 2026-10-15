#include <iostream>


#include "Deck.h"

#define PLAYERS 5
#define CARDS_PER_PLAYER 4

#define FILENAME "../deck.txt"

int main() {

    Deck d;
    d.fillStandardDeck();
    d.shuffle();
    std::vector<Deck> players = d.deal(PLAYERS,CARDS_PER_PLAYER);

    std::cout << "Players: " << PLAYERS << ", cards per player: " << CARDS_PER_PLAYER << std::endl;
    std::cout << "Cards left in deck: " << d.size() << std::endl;

    for (int i=0; i < PLAYERS; i++) {
        std::cout << "Player " << i+1 << " cards: " << players[i].print_deck() << std::endl;
    }

    d.sort();
    std::cout << "Sorted deck: " << d.print_deck() << std::endl;

    d.saveToFile(FILENAME);
    Deck loaded;
    loaded.readFromFile(FILENAME);
    std::cout << "Loaded deck: " << loaded.print_deck() << std::endl;
    std::cout << "Save/load matches: " << std::boolalpha
              << (d.print_deck() == loaded.print_deck()) << std::endl;

    return 0;
}
