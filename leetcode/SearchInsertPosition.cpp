#include <iostream>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int m = (l + r) / 2;

            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        return nums[l] < target ? l + 1 : l;
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
    const int LOCAL_LENGTH = 5;
    //int a[LOCAL_LENGTH] = {1, 3, 5, 6};
    //int a[LOCAL_LENGTH] = {6, 5, 3, 1};
    //int a[LOCAL_LENGTH] = {6};
    //int a[LOCAL_LENGTH] = {1, 3};
    //int a[LOCAL_LENGTH] = {3, 1};
    //int a[LOCAL_LENGTH] = {1, 3, 5, 6, 8};
    int a[LOCAL_LENGTH] = {8, 6, 5, 3, 1};
    vector<int> nums(a, a + LOCAL_LENGTH);;
    printVector<int>(nums);
    int target = 0;
    cout << "Please enter target: ";
    cin >> target;
    cout << sln.searchInsert(nums, target) << endl;
    return 0;
}
