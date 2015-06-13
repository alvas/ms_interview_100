#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
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
    cout << "Please enter target: ";
    cin >> target;
    int a[] = {5, 7, 7, 8, 8, 10};
    vector<int> nums(a, a + SIZE(a));
    printVector<int>(nums);
    vector<int> r = sln.searchRange(nums, target);
    printVector<int>(r);
    return 0;
}
