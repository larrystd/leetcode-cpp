#include <bits/stdc++.h>
#include <cstdint>
#include <cmath>

using namespace std;

class Solution {
public:
    const int INTMAX = INT32_MAX;
    const int INTMIN = INT32_MIN;
    int numbit(int x) const {
        int num = 0;
        while (x) {
            num ++;
            x /= 10;
        }
        return num;
    }
    int reverse(int x) {
        if (x == INT32_MIN) {  // special case
            return 0;
        }
        bool flag_neg = x < 0;
        x = abs(x);
        int y = 0;
        int num_bit = numbit(x);  // num_bit >= 1 and <= 10
        if (num_bit < 10) {
            while (x) {
                y = y* 10 + x % 10;
                x /= 10;
            }
            return !flag_neg ? y:-y;
        }
        bool isvalid = false;
        for (int i = 1; i <= 10; i++) {
            int temp = x % 10;
            int temp_edge = INTMAX / (int)(pow(10, 10-i)) % 10;
            if (i == 10 && flag_neg && temp == temp_edge+1) {
                y = -y;
                y = y * 10 - temp;
                return !flag_neg ? y:-y;
            }

            if (temp < temp_edge) {
                isvalid = true;  // enough to compare
            }
            if (!isvalid && temp > temp_edge) {
                return 0;
            }
            y = y * 10 + temp;
            x /= 10;
        }
        return !flag_neg ? y:-y;
    }
};

int main() {
    Solution solu;
    cout << (long(1)<<31)-1 <<endl;  // 2147483647
    /*
    cout << solu.reverse(2063847412) <<endl;
    cout << solu.reverse(-2063847412) <<endl;
    cout << solu.reverse(0) <<endl;
    cout << solu.reverse(123) <<endl;
    cout << solu.reverse(-123) <<endl;
    cout << solu.reverse(120) <<endl;
    cout << solu.reverse(-2147483412) <<endl;
    */
    cout << solu.reverse(-2147483648) <<endl;
    return 0;
}