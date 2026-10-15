//
// Created by piotrsiembab on 10/15/26.
//

#ifndef INC_14_10_DECK_H
#define INC_14_10_DECK_H

#include <utility>

#include "Card.h"

class Deck {
    std::vector<Card> deck;
public:
    Deck() {}
    Deck(std::vector<Card> v) : deck(std::move(v)) {}
    void fillStandardDeck();
    void shuffle();
    Card drawCard();
    std::vector<Card> drawCards(size_t n);
    bool isEmpty() const;
    size_t size() const;
    std::vector<Deck> deal(size_t playersCount, size_t cardsPerPlayer);
    std::string print_deck() const;
    void sort();
    void saveToFile(const std::string& filename);
    void readFromFile(const std::string& filename);
};


#endif //INC_14_10_DECK_H