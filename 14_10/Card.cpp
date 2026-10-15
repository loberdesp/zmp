//
// Created by piotrsiembab on 10/14/26.
//

#include "Card.h"

std::string Card::toString() const {
    return rank_as_string[static_cast<int>(r)] + " of " + suit_as_string[static_cast<int>(s)];
}
