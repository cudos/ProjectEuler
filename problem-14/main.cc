// Copyright 2015, Jens Hoffmann
//
// Longest Collatz sequence
// Problem 14
//
// The following iterative sequence is defined for the set of positive
// integers:
//
//     n → n/2 (n is even)
//     n → 3n + 1 (n is odd)
//
//     Using the rule above and starting with 13, we generate the following sequence:
//     13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
//
//     It can be seen that this sequence (starting at 13 and finishing at 1)
//     contains 10 terms. Although it has not been proved yet (Collatz
//     Problem), it is thought that all starting numbers finish at 1.
//
//     Which starting number, under one million, produces the longest chain?
//
//     NOTE: Once the chain starts the terms are allowed to go above one million.
//
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


std::vector<long> cache;


int getCollatzLength(long x, int ret) {
    if ((x - 1) < cache.size()) return ret + cache[x - 1];
    int result = 0;
    if (x % 2 == 0) {
        result = getCollatzLength(x / 2, ret + 1);
    } else {
        result = getCollatzLength(3*x + 1, ret + 1);
    }
    return result;
}


int getCollatzLength(long x) {
    long result = getCollatzLength(x, 0);
    cache.push_back(result);
    return result;
}


int main() {
    cache.push_back(1);
    int max = 0;
    int maxi = 0;

    for (int i = 2; i < 1000*1000; ++i) {
        int cl = getCollatzLength(i);
        if (cl > max) {
            max = cl;
            maxi = i;
        }
    }

    std::cout << "Result: " << maxi << std::endl;
    return 0;
}

