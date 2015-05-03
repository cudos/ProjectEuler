// Copyright 2015 Jens Hoffmann
//
// Largest prime factor
// Problem 3
//
// The prime factors of 13195 are 5, 7, 13 and 29.
//
// What is the largest prime factor of the number 600851475143 ?
//
#include <math.h>
#include <stdio.h>
#include <limits>

bool isPrime(long x) {
    if (x == 0 || x == 1) return false;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (long i = 5; i*i < x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long n = 600851475143;
    long maxPrime = 0;

    for (long x = sqrt(n); x > 0; --x) {
        if (n % x == 0 && isPrime(x)) {
            maxPrime = x;
            break;
        }
    }

    printf("Result: %ld\n", maxPrime);

    return 0;
}

