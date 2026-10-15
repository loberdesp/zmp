//
// Created by piotrsiembab on 10/15/26.
//

#include "Deck.h"

#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>

void Deck::fillStandardDeck() {
    for (int i=0; i < static_cast<int>(Suit::Count); i++) {
        for (int j=0; j < static_cast<int>(Rank::Count); j++) {
            deck.emplace_back(static_cast<Suit>(i), static_cast<Rank>(j));
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
}

Card Deck::drawCard() {
    Card c{};
    if (!isEmpty()) {
        c = deck.back();
        deck.pop_back();
    } else {
        std::cout << "No cards in deck, can't draw a card!" << std::endl;
    }
    return c;
}

std::vector<Card> Deck::drawCards(size_t n) {
    std::vector<Card> subDeck(n);
    if (n <= size()) {
        std::move(deck.end()-n, deck.end(), subDeck.begin());
        deck.erase(deck.end()-n, deck.end());
    } else {
        std::cout << "Deck has less than " << n << " cards, can't draw!" << std::endl;
    }
    return subDeck;
}

bool Deck::isEmpty() const {
    return deck.empty();
}


size_t Deck::size() const {
    return deck.size();
}


std::vector<Deck> Deck::deal(const size_t playersCount, const size_t cardsPerPlayer) {
    std::vector<Deck> players;
    for (int i=0; i < playersCount; i++) {
        players.emplace_back(drawCards(cardsPerPlayer));
    }
    return players;
}

void Deck::sort() {
    std::sort(deck.begin(), deck.end());
}

std::string Deck::print_deck() const {
    std::string res;
    for (auto x : deck) {
        res += x.toString();
        res += ", ";
    }
    return res;
}


void Deck::saveToFile(const std::string& filename) {
    std::ofstream outfile (filename);
    outfile << print_deck() << std::endl;
}

void Deck::readFromFile(const std::string& filename) {
    std::ifstream file (filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "failed to open " << filename << '\n';
    } else {
        std::string rankString, ofString, suitString;
        while (file >> rankString >> ofString >> suitString) {
            suitString.pop_back();
            auto rankIter = std::find(rank_as_string.begin(), rank_as_string.end(), rankString);
            auto suitIter = std::find(suit_as_string.begin(), suit_as_string.end(), suitString);
            if (rankIter!=rank_as_string.end() && suitIter!=suit_as_string.end()) {
                std::size_t rankIndex = std::distance(std::begin(rank_as_string), rankIter);
                std::size_t suitIndex = std::distance(std::begin(suit_as_string), suitIter);
                deck.emplace_back(static_cast<Suit>(suitIndex), static_cast<Rank>(rankIndex));
            }
        }
    }
}