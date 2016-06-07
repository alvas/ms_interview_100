#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (nums[m] < nums[m + 1])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        return l;
    }

    int findPeakElement1(vector<int>& nums) {
        int peak = 0;
        int size = nums.size();

        if (size == 0)
        {
            return peak;
        }

        // use r = size - 1 make life easier
        int l = 0, r = size - 1;

        // Be very careful about the boundary checking.
        // At any time, elements outside of the range is smaller than the bounder inside the range.
        while (l < r)
        {
            int m = (l + r) / 2;
            
            if (l <= m - 1 && m + 1 <= r)
            {
                if (nums[m - 1] < nums[m])
                {
                    if (nums[m] > nums[m + 1])
                    {
                        return m;
                    }
                    else
                    {
                        l = m;
                    }
                }
                else
                {
                    r = m - 1;
                }
            }
            else if (m + 1 <= r)
            {
                if (nums[m] < nums[m + 1])
                {
                    return m + 1;
                }
                else
                {
                    return m;
                }
            }
            else if (l <= m - 1)
            {
                if (nums[m - 1] < nums[m])
                {
                    return m;
                }
                else
                {
                    return m - 1;
                }
            }
        }

        return peak;
    }
};

int main()
{
    Solution sln;
    vector<int> nums;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    initializeRandomVector(nums, n);
    printVector<int>(nums);
    std::cout << sln.findPeakElement(nums) << endl;
    std::cout << sln.findPeakElement1(nums) << endl;
    return 0;
}
