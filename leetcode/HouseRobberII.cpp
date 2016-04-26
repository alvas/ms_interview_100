#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();

        if (m <= 1)
        {
            return m == 0 ? 0 : nums[0];
        }

        return max(rob(nums, 0, m - 1), rob(nums, 1, m));
    }

    int rob(vector<int> &nums, int s, int e)
    {
        if (e - s <= 1)
        {
            return nums[s];
        }

        vector<int> dp(e, 0);
        dp[s] = nums[s];
        dp[s + 1] = max(nums[s], nums[s + 1]);

        for (int i = s + 2; i < e; ++i)
        {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp.back();
    }

    int rob2(vector<int>& nums) {
        int sz = nums.size();

        if (sz == 0)
        {
            return 0;
        }
        else if (sz == 1)
        {
            return nums[0];
        }
        else if (sz == 2)
        {
            return max(nums[0], nums[1]);
        }
        else if (sz == 3)
        {
            return max(nums[0], max(nums[1], nums[2]));
        }

        vector<int> sum1(sz - 1), sum2(sz);
        sum1[0] = nums[0];
        sum1[1] = nums[0];

        // chose the first one, but not the last one
        for (int i = 2; i < sz - 1; ++i)
        {
            sum1[i] = max(sum1[i - 1], sum1[i - 2] + nums[i]);
        }

        sum2[0] = 0;
        sum2[1] = nums[1];

        // don't choose the first one, but the last one
        for (int i = 2; i < sz; ++i)
        {
            sum2[i] = max(sum2[i - 1], sum2[i - 2] + nums[i]);
        }

        // the answer is the bigger one
        return max(sum1[sz - 2], sum2[sz - 1]);
    }

    int rob_recursive(vector<int>& nums) {
        int sz = nums.size();
        vector<bool> mark(sz, false);
        return solve(nums, mark, sz - 1);
    }

    int solve(vector<int> &nums, vector<bool> &mark, int index)
    {
        int sz = nums.size();

        if (index < 0)
        {
            return 0;
        }
        else if (index == 0)
        {
            if (mark[sz - 1])
            {
                return 0;
            }
            else
            {
                return nums[0];
            }
        }
        else if (index == 1)
        {
            if (mark[sz - 1])
            {
                return nums[1];
            }
            else
            {
                return max(nums[0], nums[1]);
            }
        }

        int v1 = solve(nums, mark, index - 1);
        mark[index] = true;
        int v2 = solve(nums, mark, index - 2) + nums[index];
        mark[index] = false;
        return max(v1, v2);
    }
};

int main()
{
    Solution sln;
    const int LEN = 10;
    vector<int> nums;
    srand(unsigned(time(0)));
    initializeRandomVector(nums, rand() % LEN);
    //printVector<int>(nums);

    //for (auto n : nums)
    //{
        //std::cout << n << "\t";
    //}
    
    //std::cout << endl;
    
    for_each(nums.begin(), nums.end(), [](int n){
        std::cout << n << "\t";
    });

    std::cout << endl;
    std::cout << sln.rob_recursive(nums) << endl;
    std::cout << sln.rob(nums) << endl;
    return 0;
}
