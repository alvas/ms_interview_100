#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto itr1 = lower_bound(nums.begin(), nums.end(), target);
        vector<int> res(2, -1);

        if (itr1 == nums.end() || *itr1 != target)
        {
            return res;
        }
        else
        {
            res[0] = std::distance(nums.begin(), itr1);
            auto itr2 = upper_bound(nums.begin(), nums.end(), target);
            res[1] = std::distance(nums.begin(), itr2) - 1;
        }

        return res;
    }

    vector<int> searchRange1(vector<int>& nums, int target) {
        vector<int> r(2, -1);
        int size = nums.size();
        int startIdx = binarySearch(nums, 0, size, target);

        if (startIdx == -1)
        {
            return r;
        }
        else
        {
            int prevStartIdx = startIdx;

            while (startIdx != -1)
            {
                prevStartIdx = startIdx;
                startIdx = binarySearch(nums, 0, startIdx, target);
            }

            r[0] = prevStartIdx;
            int endIdx = prevStartIdx, prevEndIdx = endIdx;

            while (endIdx != -1)
            {
                prevEndIdx = endIdx;
                // Be careful to + 1 to endIdx here.
                endIdx = binarySearch(nums, endIdx + 1, size, target);
            }

            r[1] = prevEndIdx;
        }

        return r;
    }

    // Be careful about the index here.
    int binarySearch(const vector<int> &nums, int l, int r, int target)
    {
        if (l >= r)
        {
            return -1;
        }

        if (target == nums[l])
        {
            return l;
        }
        else if (target < nums[l])
        {
            return -1;
        }
        else if (nums[r - 1] == target)
        {
            return r - 1;
        }
        else if (nums[r - 1] < target)
        {
            return -1;
        }

        while (l < r)
        {
            int m = (l + r) / 2;

            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sln;
    int target = 0;
    std::cout << "Please enter target: ";
    cin >> target;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    printVector<int>(nums);
    vector<int> r = sln.searchRange(nums, target);
    printVector<int>(r);
    return 0;
}
