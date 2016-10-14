#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) {
            return false;
        }

        int root = floorSqrt(num);
        return root * root == num;
    }

    int32_t floorSqrt(int32_t x) {
        double y = x;
        int64_t i = 0x5fe6eb50c7b537a9;
        y = *(double*)&(i = i - (*(int64_t*)&y) / 2);
        y = y * (3 - x * y * y) * 0.5;
        y = y * (3 - x * y * y) * 0.5;
        i = x * y + 1;
        return i - (i * i > x);
    }

    // Newton's Method
    bool isPerfectSquare3(int num) {
        int x = num;

        while (x * x > num) {
            x = (x + (num / x)) / 2;
        }

        return x * x == num;
    }

    // 1 = 1
    // 4 = 1 + 3
    // 9 = 1 + 3 + 5
    // 16 = 1 + 3 + 5 + 7 
    // 25 = 1 + 3 + 5 + 7 + 9
    // ...
    bool isPerfectSquare2(int num) {
        int i = 1;
        
        while (num > 0) {
            num -= i;
            i += 2;
        }

        return num == 0;
    }

    bool isPerfectSquare_binary_search(int num) {
        if (num < 0) {
            return 0;
        }
        else if (num == 1) {
            return 1;
        }

        long l = 1, r = num;

        while (l < r) {
            long m = l + (r - l) / 2;
            long sqr = m * m;

            if (sqr == num) {
                return true;
            }
            else if (sqr < num) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        return false;
    }
};

int main() {
    Solution sln;

    for (int i = 0; i < 65; ++i) {
        cout << i << " : " << sln.isPerfectSquare(i) << endl;
    }

    cout << sln.isPerfectSquare(808201) << endl;

    return 0;
}
