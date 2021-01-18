// Copyright Roman Balayan @ 2021

#include <iostream>
#include "postfix.h"

int main() {
    std::string s1("2 + 6 * 3 / (4 - 2)");
    std::string s2 = infix2prefix(s1);
    std::cout << s2;  // 2 6 3 * 4 2 - / +

    return 0;
}
