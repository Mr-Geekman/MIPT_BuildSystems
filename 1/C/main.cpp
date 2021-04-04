#include <iostream>
#include "main.h"

void demo() {
    int value = 42;
    std::cout << "42 + 2 = 44" << TP::add_2(value) << std::endl;
    std::cout << "42 + 3 = 45" << TP::add_3(value) << std::endl;
}

int main() {
    demo();
    return 0;
}