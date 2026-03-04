#pragma once
#include "IInfusion.h"

class MultiplierAmplifier : public IInfusion {
private:
    int multiplier;

public:
    MultiplierAmplifier(int value) : multiplier(value) {}

    int apply(int score) override {
        return score * multiplier;
    }

    std::string getName() override {
        return "Multiplier x" + std::to_string(multiplier);
    }
};