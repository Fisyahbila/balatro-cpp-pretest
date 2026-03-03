#include <iostream>
#include "Card.h"

int main() {
    Card c{Suit::Spades, 10};
    std::cout << "Test Card: " << c.toString() << "\n";
    return 0;
}