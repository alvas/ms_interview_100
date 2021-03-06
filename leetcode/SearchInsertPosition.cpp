#include <iostream>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        // be careful about <= here for [1] case, target is 0
        bool ascending = nums.front() <= nums.back();

        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (nums[m] == target)
            {
                return r;
            }
            else if ((nums[m] < target && ascending) || (nums[m] > target && !ascending))
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        return r;
    }

    // be careful about the corner conditions
    int searchInsert1(vector<int>& nums, int target) {
        int size = nums.size();

        if (size == 0)
        {
            return 0;
        }

        bool increasing = true;

        // Be careful the ">" here. Don't use ">=". 
        if (nums[0] > nums[size - 1])
        {
            increasing = false;
        }

        int l = 0, r = size;

        while (l < r)
        {
            int mid = (l + r) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                if (increasing)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            else
            {
                if (increasing)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }

        if (l < 0)
        {
            l = 0;
        }
        else if (l == 0 && target < nums[0])
        {
            if (increasing)
            {
                l = 0;
            }
            else
            {
                l = 1;
            }
        }
        else if (l >= size)
        {
            l = size;
        }
        else if (l == size - 1 && nums[size - 1] < target)
        {
            if (increasing)
            {
                l = size;
            }
            else
            {
                l = size - 1;
            }
        }
        else if (nums[l] < target)
        {
            if (increasing)
            {
                l = l + 1;
            }
        }

        return l;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {1, 3, 5, 6};
    //vector<int> nums = {6, 5, 3, 1};
    //vector<int> nums = {6};
    //vector<int> nums = {1, 3};
    //vector<int> nums = {3, 1};
    //vector<int> nums = {1, 3, 5, 6, 8};
    vector<int> nums = {8, 6, 5, 3, 1};
    printVector<int>(nums);
    int target = 0;
    std::cout << "Please enter target: ";
    cin >> target;
    std::cout << sln.searchInsert(nums, target) << endl;
    return 0;
}
