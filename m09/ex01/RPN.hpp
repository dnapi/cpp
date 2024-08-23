#pragma once

#include <iostream>
#include <string>
#include <stack>

class RPN{
public:
    RPN() = default;
    ~RPN() = default;
    float calcExpr(const std::string& expr);
    void apply(int);
    bool isValid();

private:
    size_t pos_ = 0;
    int valid_ = 1;
    std::stack<float> stack_;
    RPN(const RPN&) = default;
    RPN& operator=(const RPN&) = default;
};