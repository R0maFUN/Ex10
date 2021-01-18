// Copyright Roman Balayan @ 2021

#include "postfix.h"
#include <iostream>

std::string infix2postfix(std::string infix) {
    std::unordered_map<char, int> priorities({
            {'(', 0},
            {')', 1},
            {'+', 2},
            {'-', 2},
            {'*', 3},
            {'/', 3}
        });
    std::string prefix;
    MyStack<char> operators(200);
    for (auto it = infix.begin(); it != infix.end(); ++it) {
        if (priorities.count(*it) > 0) {
            if (*it == ')') {
                char op;
                while ((op = operators.pop()) != '(') {
                    prefix += op;
                    prefix += ' ';
                }
                continue;
            }
            if (operators.isEmpty()) {
                operators.push(*it);
                continue;
            } else if (priorities[*it] == 0) {
                operators.push(*it);
                continue;
            } else if (priorities[*it] > priorities[operators.get()]) {
                operators.push(*it);
                continue;
            }
            char op;
            while (!operators.isEmpty() &&
                   priorities[operators.get()] >= priorities[*it]) {
                prefix += operators.pop();
                prefix += ' ';
            }
            operators.push(*it);
        } else if (*it == '.') {
            prefix.pop_back();
            prefix += *it;
        } else if (*it != ' ') {
            prefix += *it;
            prefix += ' ';
        }
        
    }
    while (!operators.isEmpty()) {
        prefix += operators.pop();
        prefix += ' ';
    }
    prefix.pop_back();
    return prefix;
}

