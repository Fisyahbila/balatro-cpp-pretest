#pragma once
#include "IScoringStrategy.h"

class SumStrategy : public IscoringStrategy {
public:
    int calculateScore(const std::vector<Card>& hand) override {
        int score = 0;

        for (const auto& card : hand) {
            score += card.rank;
        }

        return score;
    }
};