#pragma once
#include <iostream>

#include "../Deck.h"
#include "../scoring/SumStrategy.h"
#include "../infusion/InfusionChain.h"
#include "../shop/ShopSystem.h"

class RunSession {
private:
    Deck deck;
    SumStrategy scoring;
    InfusionChain chain;
    ShopSystem shop;

public:

    void start() {

        deck.shuffle();

        for (int round = 1; round <= 3; round++) {

            std::cout << "\n=== ROUND " << round << " ===\n";

            auto hand = deck.draw(5);

            std::cout << "Drawn Hand:\n";
            for (const auto& card : hand) {
                std::cout << card.toString() << " ";
            }
            std::cout << "\n";

            int baseScore = scoring.calculateScore(hand);

            std::cout << "Base Score: " << baseScore << "\n";

            int finalScore = chain.applyAll(baseScore);

            std::cout << "Final Score: " << finalScore << "\n";

            IInfusion* bought = shop.openShop();

            if (bought != nullptr) {
                chain.addInfusion(bought);
                std::cout << "Infusion added to chain!\n";
            }
        }

        std::cout << "\n=== RUN COMPLETE ===\n";
    }
};