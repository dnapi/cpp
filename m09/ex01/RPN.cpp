/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:56:28 by apimikov          #+#    #+#             */
/*   Updated: 2024/08/23 12:00:28 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

float RPN::calcExpr(const std::string& expr){
    expr_ = expr;
    if (expr.empty()){
        std::cerr << "Error: empty input\n";
        valid_ = 0;
        return 0;
    }
    size_t i = 0;
    for (auto & c: expr){
        if (!isspace(c))
            break;
        ++i;
    }
    if (i == expr.size()){
        std::cerr << "Error: empty input\n";
        valid_ = 0;
        return 0;
    }
    for (auto & c: expr){
        pos_++;
        if (isspace(c)) continue;
        if (isdigit(c)){
            stack_.push(c - 48);
            continue;
        }
        if ('+' == c || '-' == c || '*' == c || '/' == c){
            apply(c);
        }
        else {
            std::cerr << "Error: the symbol '" << c << "' is not supported." << "see position " << pos_ << ".\n";
            valid_ = 0;
        }
        if (valid_)
            continue;
        valid_ = 0;
        return 0;
    }
    size_t size = 0;
    if (stack_.empty()){
        valid_ = 0;
        return 0;
    }
    float result =  stack_.top();
    while (!stack_.empty()){
        size++;
        stack_.pop();
    }
    if (size == 1){
        valid_ = 1;
        return result;
    }
    std::cerr << "Error: the RPN expression is not complited. see position " << pos_ << ".\n";
    valid_ = 0;
    return 0;
}

void RPN::print_error(){
    std::cerr << "    in input \"" << expr_ << "\".\n";
    std::cerr <<  std::string(13 + pos_, ' ') << "^" << ".\n";
}

void RPN::apply(int c){
    float a;
    float b;
    if (!stack_.empty())
        b = stack_.top();
    else {
        valid_ = 0;
        std::cerr << "Error: no argument for '" << static_cast<char>(c) <<"' at position " << pos_ << ".\n";
        return ;
    }
    stack_.pop();
    if (!stack_.empty())
        a = stack_.top();
    else {
        valid_ = 0;
        std::cerr << "Error: no argument for '" << static_cast<char>(c) <<"' at position " << pos_ << ".\n";
        return ;
    }
    stack_.pop();
    switch (c){
        case '+':
            stack_.push(a + b);
            return ;
        case '-':
            stack_.push(a - b);
            return ;
        case '*':
            stack_.push(a * b);
            return ;
        case '/':
            stack_.push(a / b);
            return ;
    }
}

bool RPN::isValid(){
    return valid_;
}