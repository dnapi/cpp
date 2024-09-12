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
    void print_error();

private:
    size_t pos_ = 0;
    int valid_ = 1;
    int number_entries = 0;
    std::string expr_;
    std::stack<float> stack_;
    RPN(const RPN&) = default;
    RPN& operator=(const RPN&) = default;
};