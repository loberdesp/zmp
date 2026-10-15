//
// Created by piotrsiembab on 10/14/26.
//

#ifndef INC_14_10_CARD_H
#define INC_14_10_CARD_H
#include <string>
#include <vector>

enum class Rank {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
    Count,
};

const std::vector<std::string> rank_as_string{
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Jack",
    "Queen",
    "King",
    "Ace"
};

enum class Suit {
    Spade,
    Heart,
    Diamond,
    Club,
    Count
};

const std::vector<std::string> suit_as_string {
    "Spades",
    "Hearts",
    "Diamonds",
    "Clubs"
};

class Card {
    Suit s;
    Rank r;
public:
    Card() = default;
    Card(Suit s, Rank r) : s(s), r(r) {}
    std::string toString() const;

    bool operator<(const Card& other) const {
        return r < other.r;
    }

    bool operator>(const Card& other) const {
        return r > other.r;
    }

    bool operator==(const Card& other) const {
        return r == other.r;
    }
};


#endif //INC_14_10_CARD_H