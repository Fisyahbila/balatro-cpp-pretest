#pragma once
#include <string>

class IInfusions {
public:
    virtual int apply(int score) = 0;
    virtual std::string getname() = 0;
    virtual ~IInfusions() {}
};