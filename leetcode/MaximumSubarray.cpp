#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums.size();
        return maxSub(nums, 0, m);
    }

    int maxSub(vector<int> &nums, int b, int e)
    {
        if (e - b <= 0)
        {
            return INT_MIN;
        }
        else if (e - b == 1)
        {
            return nums[b];
        }

        int m = b + (e - b) / 2;
        int maxV = max(maxSub(nums, b, m), maxSub(nums, m, e));
        int lMax = INT_MIN, rMax = INT_MIN;
        int sum = 0;

        for (int i = m - 1; i >= b; --i)
        {
            sum += nums[i];
            lMax = max(sum, lMax);
        }

        sum = 0;

        for (int i = m; i < e; ++i)
        {
            sum += nums[i];
            rMax = max(sum, rMax);
        }

        maxV = max(maxV, lMax);
        maxV = max(maxV, rMax);
        maxV = max(maxV, lMax + rMax);
        return maxV;
    }

    // Could be improved??
    int maxSubArray1(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
        {
            return 0;
        }

        int maxV = nums[0], sum = nums[0];

        for (int i = 1; i < size; ++i)
        {
            // when sum is small than 0, we set the sum to the last negative nums[i]
            // because adding negative number together will make sum smaller and smaller
            // don't need to add any negative to it.
            // WHEN sum is negative, nums[i] is positive, sum is reset to nums[i] which is the first positive after a negative sequence.
            if (sum < 0)
            {
                sum = nums[i];
            }
            else
            {
                // as long as sum is positive, we add nums[i] to sum, because even nums[i] is negative, sum + nums[i] + nums[i + 1] could still bigger than sum, so the continous sum will be bigger.
                sum += nums[i];
            }

            maxV = max(maxV, sum);
        }

        return maxV;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {-2, -1, -3, 4, -1, 2, 1, -5, 4};
    //vector<int> nums = {-1};
    //vector<int> nums = {-1, -2};
    //vector<int> nums = {-2, -1};
    //vector<int> nums = {-3, -2, -1};
    //vector<int> nums = {-3, -1, -2};
    //vector<int> nums = {-2, -3, -1};
    //vector<int> nums = {-1, -3, -2};
    //vector<int> nums = {-1, -3, -2, 2};
    std::cout << sln.maxSubArray(nums) << endl;
    return 0;
}
