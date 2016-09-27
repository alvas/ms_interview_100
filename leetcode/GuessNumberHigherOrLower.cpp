#include <iostream>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
//int guess(int num);
int guess(int num) {
    const int target = 1;

    if (num == target) {
        return 0;
    }
    else if (target < num) {
        return -1;
    }
    else
    {
        return 1;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, r = n;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (guess(m) == 0) {
                return m;
            }
            else if (guess(m) == -1) {
                r = m - 1;
            }
            else if (guess(m) == 1) {
                l = m + 1;
            }
        }

        return l;
    }
};

int main() {
    Solution sln;
    //int n = 578;
    //int n = 2126753390;
    int n = 1;
    cout << sln.guessNumber(n) << endl;
    return 0;
}
