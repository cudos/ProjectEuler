// Copyright 2015, Jens Hoffmann
//
// Lattice paths
// Problem 15
//
// Starting in the top left corner of a 2×2 grid, and only being able to move
// to the right and down, there are exactly 6 routes to the bottom right
// corner.
//
// How many such routes are there through a 20×20 grid?
//
#include <iostream>
#include <sstream>


std::string matrixToString(long m[][21]) {
    std::ostringstream oss;
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 21; ++j) {
            oss << m[i][j] << " ";
        }
        oss << std::endl;
    }
    return oss.str();
}


int main() {
    long matrix[21][21];
    for (int i = 0; i < 21; ++i) {
        for (int j = 0; j < 21; ++j) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < 21; ++i) {
        matrix[0][i] = 1;
        matrix[i][0] = 1;
    }
    for (int i = 1; i < 21; ++i) {
        for (int j = 1; j <= i; ++j) {
            matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1];
            if (i != j) {
                matrix[j][i] += matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
    }

    // std::cout << matrixToString(matrix) << std::endl;

    std::cout << "Result: " << matrix[20][20] << std::endl;
    return 0;
}

