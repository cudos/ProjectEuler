// Copyright 2015 Jens Hoffmann
//
// Smallest multiple
// Problem 5
//
// 2520 is the smallest number that can be divided by each of the numbers from
// 1 to 10 without any remainder.
//
// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?
//
#include <stdio.h>


bool isDivisible(int x) {
    for (int i = 20; i > 2; --i) {
        if (x % i) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 20;

    while(1) {
        if (isDivisible(n)) {
            break;
        }
        n += 20;
    }
    printf("Result: %d\n", n);

    return 0;
}

