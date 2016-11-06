#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 0) {
            return 0;
        }


        // ((1 + k) * k ) / 2 <= n < (((1 + (k + 1))) * (k + 1)) / 2
        long l = 1, r = n;
        // Be careful about initialization: long n2 = n * 2 would overflow, because n and 2 are both integer.
        long n2 = n;
        n2 *= 2;

        while (l < r) {
            long m = l + ((r - l) >> 1);
            long k = m * m + m;

            if (k == n2) {
                // Be careful here, setting the value l; otherwise l would be not be set correctly.
                l = m;
                break;
            }
            else if (k < n2) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        // checking there to make sure less then n2
        if (l * l + l > n2) {
            l--;
        }

        return l;
    }
};

int main() {
    Solution sln;
    //int n = 8;
    //int n = 3;
    int n = 1804289383;
    cout << sln.arrangeCoins(n) << endl;
    return 0;
}
