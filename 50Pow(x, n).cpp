#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double base = x;
        double x_pow_n = 1;
        bool neg_flag = false;
        if (n < 0) {
            neg_flag = true;
            n = -(n+1);  // avoid n = INT_MIN
        }
        while(n) {
            if (n & 1) {
                x_pow_n *= base;
            }
            base *= base;
            n >>= 1;
        }
        return !neg_flag ? x_pow_n : 1/(x_pow_n*x);
    }
};