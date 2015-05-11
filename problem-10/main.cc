// Copyright 2015, Jens Hoffmann
//
// Summation of primes
// Problem 10
//
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//
// Find the sum of all the primes below two million.
//
#include <stdio.h>


bool isPrime(long x) {
    if (x == 0 || x == 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (long i = 5; i*i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}


int main() {
    long sum = 0;

    for (long i = 1; i < 2*1000*1000; ++i) {
    // for (long i = 1; i < j; ++i) {
        if (isPrime(i)) sum += i;
    }
    printf("Result: %ld\n", sum);

    return 0;
}

