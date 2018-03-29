#include <iostream>
#include <numeric>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;

        for (int i = 1, j = n; i <= j; ) {
            if (k > 1) {
                ans.push_back(k-- % 2 ? i++ : j--);
            }
            else {
                ans.push_back(k % 2 ? i++ : j--);
            }
        }

        return ans;
    }

    vector<int> constructArray1(int n, int k) {
        vector<int> num(n);
        iota(num.begin(), num.end(), 1);

        if (k == 1) {
            return num;
        }

        for (int i = 0; i < k; i++) {
            if (2 * i < k) {
                num[2 * i] = i + 1; 
            }

            if (2 * i + 1 < k) {
                num[2 * i + 1] = n - i;
            }
        }

        if (k % 2 == 0) {
            int start = n - k / 2;

            for (int i = k; i < n; ++i) {
                num[i] = start--;
            }
        }
        else {
            int start = (k + 1) / 2 + 1;

            for (int i = k; i < n; ++i) {
                num[i] = start++;
            }
        }

        return num;
    }
};

int main()
{
    Solution sln;
    //int n = 3, k = 1;
    //int n = 3, k = 2;
    //int n = 34, k = 15;
    //int n = 10, k = 3;
    //int n = 10, k = 4;
    //int n = 11, k = 4;
    int n = 11, k = 3;
    vector<int> ans = sln.constructArray(n, k);
    printVector<int>(ans);
    return 0;
}
