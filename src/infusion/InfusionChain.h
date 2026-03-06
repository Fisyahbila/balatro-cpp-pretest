#pragma once
#include <vector>
#include "IInfusion.h"

class InfusionChain {
private:
    std::vector<IInfusion*> infusions;

public:
    void addInfusion(IInfusion* infusion) {
        if (infusions.size() < 5) {
            infusions.push_back(infusion);
        }
    }

    int applyAll(int score) {
        int result = score;

        for (auto infusion : infusions) {
            result = infusion->apply(result);
        }

        return result;
    }
};