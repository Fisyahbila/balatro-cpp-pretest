#pragma once
#include <string>

class IInfusion {
public:
    virtual int apply(int score) = 0;
    virtual std::string getName() = 0;
    virtual ~IInfusion() {}
};