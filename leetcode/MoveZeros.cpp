#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include "NormalData.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();

        int i = 0;

        while (i < sz)
        {
            while (i < sz && nums[i] != 0)
            {
                i++;
            }

            int j = i;

            while (j < sz && nums[j] == 0)
            {
                j++;
            }

            if (j >= sz)
            {
                break;
            }

            std::swap(nums[i], nums[j]);
            i++;
        }
    }

    void moveZeroes1(vector<int>& nums) {
        //std::stable_partition(nums.begin(), nums.end(), [](int i){ return i != 0; });
        std::stable_partition(nums.begin(), nums.end(), std::bind2nd(std::not_equal_to<int>(), 0));
    }
};

int main()
{
    Solution sln;
    //std::vector<int> nums = {};
    //std::vector<int> nums = {0};
    std::vector<int> nums = {1};
    //std::vector<int> nums = {0, 0};
    //std::vector<int> nums = {0, 1};
    //std::vector<int> nums = {1, 0};
    //std::vector<int> nums = {1, 1};
    //std::vector<int> nums = {0, 1, 0, 3, 12};
    //sln.moveZeroes1(nums);
    sln.moveZeroes(nums);
    printVector<int>(nums);
    return 0;
}
