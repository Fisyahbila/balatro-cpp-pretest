#include <iostream>
#include "Deck.h"
#include "infusion/FlatEnhancer.h"
#include "infusion/MultiplierAmplifier.h"

int main() {
    Deck deck;
    deck.shuffle();

    auto hand = deck.draw(5);

    std::cout << "Drawn Hand:\n";
    for (const auto& card : hand) {
        std::cout << card.toString() << " ";
    }

    int score = 0;
    for (const auto& card : hand) {
        score += card.rank;
    }

    std::cout << "\nBase Score: " << score << "\n";

    FlatEnhancer flat(10);
    MultiplierAmplifier multi(2);

    int modifiedScore = flat.apply(score);
    modifiedScore = multi.apply(modifiedScore);

    std::cout << "After Infusion: " << modifiedScore << "\n";
    return 0;
}