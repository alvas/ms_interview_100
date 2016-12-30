#include <iostream>

using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        if (n <= 0 || k <= 0) {
            return 0;
        }

        return paint(n, k, 0);
    }

    int paint(int n, int k, int sameColor) {
        if (sameColor == 0) {
            if (n == 1) {
                return k;
            }
            else {
                return k * paint(n - 1, k, 1);
            }
        }
        else if (sameColor == 1) {
            if (n == 1) {
                return k;
            }
            else {
                return paint(n - 1, k, 2) + (k - 1) * paint(n - 1, k, 1);
            }
        }
        else {
            if (n == 1) {
                return k - 1;
            }
            else {
                return (k - 1) * paint(n - 1, k, 0);
            }
        }
    }
};

int main() {
    Solution sln;
    //int n = 0, k = 0;
    //int n = 4, k = 2;
    //int n = 5, k = 3;
    //int n = 2, k = 1;
    //int n = 3, k = 1;
    //int n = 2, k = 2;
    //int n = 3, k = 2;
    //int n = 4, k = 2;
    int n = 5, k = 2;
    //int n = 6, k = 2;
    //int n = 7, k = 2;
    cout << sln.numWays(n, k) << endl;
    return 0;
}
