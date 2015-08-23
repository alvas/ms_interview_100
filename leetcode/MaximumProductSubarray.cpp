#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }

        int ret = nums[0], curMax = nums[0], curMin = nums[0];

        for (int i = 1; i < n; ++i)
        {
            int tmp = curMax;
            curMax = max(max(curMax * nums[i], curMin * nums[i]), nums[i]);
            curMin = min(min(tmp * nums[i], curMin * nums[i]), nums[i]);
            ret = max(ret, curMax);
        }

        return ret;
    }

    // still time limit exceed.
    int maxProduct_1D(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }

        int res = INT_MIN;
        vector<int> dp(nums.begin(), nums.end());

        // Don't multiply all numbers and then divide them, because there would
        // be 0, and causes exception.

        for (int len = 1; len < n; ++len)
        {
            for (int i = 0; i + len < n; ++i)
            {
                dp[i] = dp[i] * nums[i + len];
                res = max(res, dp[i]);
            }
        }

        return res;
    }

    // memory limit exceed.
    int maxProduct_2D(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }

        int res = INT_MIN;
        vector<vector<int> > dp(n, vector<int>(n, INT_MIN));

        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = nums[i];
        }

        for (int len = 1; len < n; ++len)
        {
            for (int i = 0; i + len < n; ++i)
            {
                int j = i + len;
                dp[i][j] = dp[i][j - 1] * nums[j];
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }

    int maxProduct_naive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }

        int res = INT_MIN;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int prod = 1;

                for (int k = i; k < j; ++k)
                {
                    prod *= nums[k];
                }

                res = max(res, prod);
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    int a[] = {2, 3, -2, 4};
    vector<int> nums(a, a + SIZE(a));
    cout << sln.maxProduct_naive(nums) << endl;
    cout << sln.maxProduct(nums) << endl;
    return 0;
}
