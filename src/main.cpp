// Copyright Roman Balayan @ 2021

#include <iostream>
#include "MyStack.h"
#include "Stack09/postfix.h"

int main() {
    //std::cout << "Infix: ";
    //std::string in;
    //std::getline(std::cin, in);
    //std::cout << "\nPrefix:" << infix2prefix(in) << "\n";
    std::string s1("2 + 6 * 3 / (4 - 2)");
    std::string s2 = infix2prefix(s1);
    std::cout << s2;  // 2 6 3 * 4 2 - / +

    return 0;
}