// Copyright 2015 Jens Hoffmann
//
// Largest palindrome product
// Problem 4
//
// A palindromic number reads the same both ways. The largest palindrome made
// from the product of two 2-digit numbers is 9009 = 91 × 99.
//
// Find the largest palindrome made from the product of two 3-digit numbers.
//
#include <stdio.h>

bool isPalindrome(int x) {
    if (x < 0) return false;
    int xc = x;
    int xr = 0;
    while (xc) {
        xr += xc % 10;
        xr *= 10;
        xc /= 10;
    }
    xr /= 10;
    return x == xr;
}

int main() {
    int maxPalindrome = 0;
    for (int a = 999; a >= 100; --a) {
        for (int b = 999; b >= 100; --b) {
            int p = a * b;
            if (p < maxPalindrome) continue;
            if (isPalindrome(p)) {
                maxPalindrome = p;
            }
        }
    }

    printf("Result: %d\n", maxPalindrome);

    return 0;
}

