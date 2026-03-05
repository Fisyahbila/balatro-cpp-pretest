#pragma once
#include <vector>
#include "../Card.h"

class IscoringStrategy {
public:
    virtual int calculateScore(const std::vector<Card>& hand) = 0;
    virtual ~IscoringStrategy() {}
};
