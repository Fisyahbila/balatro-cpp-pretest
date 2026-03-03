#include <iostream>
#include "Deck.h"

int main() {
    Deck deck;
    deck.shuffle();

    auto hand = deck.draw(5);

    std::cout << "Drawn Hand:\n";
    for (const auto& card : hand) {
        std::cout << card.toString() << " ";
    }

    std::cout << "\n";
    return 0;
}