#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
    public:
        vector<int> selfDividingNumbers(int left, int right) {
            vector<int> res;

            for (int i = left; i <= right; ++i) {
                if (canDivide(i)) {
                    res.push_back(i);
                }
            }

            return res;
        }

        bool canDivide(int num)
        {
            if (num == 0)
                return false;

            int oldNum = num;

            while (num != 0) {
                int a = num % 10;
                num /= 10;

                if (a == 0 || oldNum % a != 0) {
                    return false;
                }
            }

            return true;
        }
};

int main()
{
    Solution sln;
    int left = 1, right = 22;
    vector<int> res = sln.selfDividingNumbers(left, right);
    printVector<int>(res);
    return 0;
}
