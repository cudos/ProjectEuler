// Copyright 2015, Jens Hoffmann
//
// 10001st prime
// Problem 7
//
// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
// that the 6th prime is 13.
//
// What is the 10 001st prime number?
//
#include <stdio.h>

bool isPrime(long x) {
    if (x == 0 || x == 1) return false;
    if (x == 2 || x == 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (long i = 5; i*i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    long x = 0;
    int cnt = 0;
    while (cnt < 10001) {
        if (isPrime(x)) {
            cnt += 1;
            // printf("cnt: %d, x: %ld\n", cnt, x);
        }
        x += 1;
    }
    printf("Result: %ld\n", x - 1);

    return 0;
}

