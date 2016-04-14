// Problem 25
//
// The Fibonacci sequence is defined by the recurrence relation:
//
//     Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
//
// Hence the first 12 terms will be:
//
//     F1 = 1
//     F2 = 1
//     F3 = 2
//     F4 = 3
//     F5 = 5
//     F6 = 8
//     F7 = 13
//     F8 = 21
//     F9 = 34
//     F10 = 55
//     F11 = 89
//     F12 = 144
//
// The 12th term, F12, is the first term to contain three digits.
//
// What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

#include <stdio.h>


int sum(int *a, int *b, int *c, int cnt) {
    int i, buf = 0, x;

    for (i = 0; i < cnt; ++i) {
        x = a[i] + b[i] + buf;
        c[i] = x % 10;
        buf = x / 10;
    }
    c[i] += buf;
    cnt += buf;

    return cnt;
}


int main() {
    int a[1000];
    int b[1000];
    int c[1000];
    int i, cnt, index;
    int *pa, *pb, *pc, *tmp;

    for (i = 0; i < 1000; i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
    }

    a[0] = 1;
    b[0] = 1;

    cnt = 1;
    index = 3;
    pa = a;
    pb = b;
    pc = c;
    while (cnt != 1000) {
        cnt = sum(pa, pb, pc, cnt);
        tmp = pa;
        pa = pb;
        pb = pc;
        pc = tmp;
        index += 1;
    }
    printf("F_%d is the first Fibonacci number with %d digits\n", index - 1, cnt);

    return 0;
}
