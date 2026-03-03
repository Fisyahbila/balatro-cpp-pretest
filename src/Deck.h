#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck() {
        for (int suit = 0; suit < 4; ++suit) {
            for (int rank = 1; rank <= 13; ++rank) {
                cards.push_back(Card{static_cast<Suit>(suit), rank});
            }
        }
    }

    void shuffle() {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(cards.begin(), cards.end(), g);
    }

    std::vector<Card> draw(int count) {
        std::vector<Card> hand;
        for (int i = 0; i < count && !cards.empty(); ++i) {
            hand.push_back(cards.back());
            cards.pop_back();
        }
        return hand;
    }
};