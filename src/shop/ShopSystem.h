#pragma once
#include <iostream>
#include <memory>
#include "../infusion/IInfusion.h"
#include "../infusion/FlatEnhancer.h"
#include "../infusion/MultiplierAmplifier.h"

class ShopSystem {
public:

    IInfusion* openShop() {

        std::cout << "\n=== SHOP ===\n";
        std::cout << "1. Flat Enhancer +10\n";
        std::cout << "2. Multiplier x2\n";
        std::cout << "0. Skip\n";

        int choice;
        std::cout << "Choose item: ";
        std::cin >> choice;

        if (choice == 1) {
            return new FlatEnhancer(10);
        }

        if (choice == 2) {
            return new MultiplierAmplifier(2);
        }

        return nullptr;
    }
};