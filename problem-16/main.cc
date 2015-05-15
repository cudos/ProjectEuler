// Copyright 2015, Jens Hoffmann
//
// Power digit sum
// Problem 16
//
// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//
// What is the sum of the digits of the number 2^1000?
//
#include <iostream>
#include <vector>


int main() {
    std::vector<int> x;
    int sum = 0;

    x.push_back(2);
    for (int i = 1; i < 1000; ++i) {
        int carry = 0;
        for (std::vector<int>::iterator it = x.begin(); it < x.end(); ++it) {
            int val = 2 * *it + carry;
            *it = val % 10;
            carry = val / 10;
        }
        if (carry) x.push_back(carry);
    }
    for (std::vector<int>::const_iterator it = x.begin(); it < x.end(); ++it) {
        std::cout << *it;
        sum += *it;
    }
    std::cout << std::endl;
    std::cout << "Result: " << sum << std::endl;

    return 0;
}

