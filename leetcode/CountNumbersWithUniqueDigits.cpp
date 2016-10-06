#include <iostream>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;

        if (n == 0) {
            ans = 1;
        }
        else if (n == 1) {
            ans = 10;
        }
        else if (n > 10) {
            return 0;
        }
        else
        {
            ans = 10;
            int sum = 9, num = 9;

            while (--n) {
                sum *= num;
                ans += sum;
                num--;
            }
        }

        return ans;
    }
};

int main() {
    Solution sln;

    for (int i = 0; i < 25; ++i) {
        cout << sln.countNumbersWithUniqueDigits(i) << endl;
    }

    return 0;
}
