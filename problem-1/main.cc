// Copyright 2015 Jens Hoffmann
//
// Multiples of 3 and 5
// Problem 1
//
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we
// get 3, 5, 6 and 9. The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.
//
#include <stdio.h>


int main() {
    int ret = 0;
    int n = 0;
    while (n + 12 < 1000) {
        ret += n + (n + 3) + (n + 5) + (n + 6) + (n + 9) + (n + 10) + (n + 12);
        n += 15;
    }
    ret += 990 + 993 + 995 + 996 + 999;
    printf("Result: %d\n", ret);

    return 0;
}

