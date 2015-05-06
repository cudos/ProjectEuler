// Copyright 2015, Jens Hoffmann
//
// Special Pythagorean triplet
// Problem 9
//
// A Pythagorean triplet is a set of three natural numbers, a < b < c, for
// which, a^2 + b^2 = c^2
//
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.
//
#include <stdio.h>


int main() {
    int result = 0;

    for (int a = 1; a <= 1000; a++) {
        for (int b = a + 1; b <= 1000; b++) {
            for (int c = b + 1; c <= 1000; c++) {
                if (a + b + c == 1000 && a*a + b*b == c*c) {
                    printf("Triplet: a=%d, b=%d, c=%d\n", a, b, c);
                    result = a * b * c;
                }
            }
        }
    }
    printf("Result: %d\n", result);

    return 0;
}

