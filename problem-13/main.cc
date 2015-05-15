// Copyright 2015, Jens Hoffmann
//
// Large sum
// Problem 13
//
// Work out the first ten digits of the sum of the following one-hundred
// 50-digit numbers (numbers.txt)
//
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>


std::string toString(const std::vector<int>& vec) {
    std::ostringstream oss;
    if (!vec.empty()) {
        std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<int>(oss, ""));
        oss << vec.back();
    }
    return oss.str();
}


int main() {
    std::ifstream file("numbers.txt");
    std::string line;
    std::vector<int> sum(60, 0);
    while (std::getline(file, line)) {
        for (int i = 0; i < line.length(); ++i) {
            int num = line[line.length() - 1 - i] - '0';
            int x = 0;
            while (num != 0) {
                int add = sum[i + x] + num;
                if (add < 10) {
                    sum[i + x] = add;
                    num = 0;
                } else {
                    sum[i + x] = add % 10;
                    num = 1;
                }
                x += 1;
            }
        }
    }
    std::reverse(sum.begin(), sum.end());
    int i = 0;
    while (i < sum.size() && sum[i] == 0) ++i;
    sum.erase(sum.begin(), sum.begin() + i);
    sum.erase(sum.begin() + 10, sum.end());
    std::cout << "Result: " << toString(sum) << std::endl;

    return 0;
}

