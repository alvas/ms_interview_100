#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        // Be careful about the size of the array. Because we need to find the first missing positive number, it could be sz + 1, if 1 to sz are in nums
        // Can't use bitset, because the sz is a variable.
        vector<bool> v(sz + 2, 0);

        for (int i = 0; i < sz; ++i)
        {
            if (nums[i] > 0 && nums[i] <= sz)
            {
                v[nums[i]] = true;
            }
        }

        int val = 0;

        // start from 1.
        for (int i = 1; i <= sz + 1; ++i)
        {
            if (!v[i])
            {
                val = i;
                break;
            }
        }

        return val;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {1, 2, 0};
    vector<int> nums = {3, 4, -1, 1};
    //vector<int> nums = {1};
    std::cout << sln.firstMissingPositive(nums) << endl;
    return 0;
}
