// Copyright 2015, Jens Hoffmann
//
// Factorial digit sum
// Problem 20
//
// n! means n × (n − 1) × ... × 3 × 2 × 1
//
// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
// Find the sum of the digits in the number 100!
//
#include <stdio.h>
#include <vector>


void vecMul(std::vector<int> *v, int x) {
    int carry = 0;
    for (int i = 0; i < v->size(); ++i) {
        int val = (*v)[i] * x + carry;
        (*v)[i] = val % 10;
        carry = val / 10;
    }
    while (carry) {
        v->push_back(carry % 10);
        carry /= 10;
    }
}


int main() {
    std::vector<int> v;
    v.push_back(1);
    for (int i = 2; i <= 100; ++i) vecMul(&v, i);
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) sum += v[i];
    printf("Result: %d\n", sum);
    return 0;
}

