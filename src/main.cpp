#include <iostream>
#include "Deck.h"
#include "infusion/FlatEnhancer.h"
#include "infusion/MultiplierAmplifier.h"
#include "scoring/SumStrategy.h"
#include "infusion/InfusionChain.h"
#include "shop/ShopSystem.h"

int main() {
    Deck deck;
    deck.shuffle();

    auto hand = deck.draw(5);

    std::cout << "Drawn Hand:\n";
    for (const auto& card : hand) {
        std::cout << card.toString() << " ";
    }
    std::cout << "\n";

    SumStrategy strategy;
    int baseScore = strategy.calculateScore(hand);

    std::cout << "Base Score: " << baseScore << "\n";

    FlatEnhancer flat(10);
    MultiplierAmplifier multi(2);

    InfusionChain chain;

    chain.addInfusion(&flat);
    chain.addInfusion(&multi);

    int finalScore = chain.applyAll(baseScore);

    std::cout << "Final Score: " << finalScore << "\n";

    ShopSystem shop;

    IInfusion* bought = shop.openShop();

    if (bought != nullptr){
        chain.addInfusion(bought);
        std::cout << "Infusion added to chain!\n";
    }

    return 0;
}