// Copyright 2015 Jens Hoffmann
//
// Even Fibonacci numbers
// Problem 2
//
// Each new term in the Fibonacci sequence is generated by adding the previous
// two terms. By starting with 1 and 2, the first 10 terms will be:
//
// 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//
// By considering the terms in the Fibonacci sequence whose values do not
// exceed four million, find the sum of the even-valued terms.
//
#include <stdio.h>


int main() {
    int ret = 2;
    int fib0 = 1;
    int fib1 = 2;
    int fib2 = 3;
    while (fib2 <= 4*1000*1000) {
        if (fib2 % 2 == 0) {
            ret += fib2;
        }
        fib0 = fib1;
        fib1 = fib2;
        fib2 = fib0 + fib1;
    }
    printf("Result: %d\n", ret);

    return 0;
}

