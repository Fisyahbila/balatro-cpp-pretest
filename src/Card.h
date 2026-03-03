#pragma once
#include <string>

enum class Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades
};

struct Card {
    Suit suit;
    int rank; // 1 - 13

    std::string toString() const {
        std::string suitSymbol;

        switch (suit) {
            case Suit::Hearts: suitSymbol = "H"; break;
            case Suit::Diamonds: suitSymbol = "D"; break;
            case Suit::Clubs: suitSymbol = "C"; break;
            case Suit::Spades: suitSymbol = "S"; break;
        }

        return std::to_string(rank) + suitSymbol;
    }
};