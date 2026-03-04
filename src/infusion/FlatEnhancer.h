#pragma once
#include "IInfusion.h"

class FlatEnhancer : public IInfusion {
private:
    int bonus;

public:
    FlatEnhancer(int value) : bonus(value) {}

    int apply(int score) override {
        return score + bonus;
    }

    std::string getName() override {
        return "Flat Enhancer +" + std::to_string(bonus);
    }
};