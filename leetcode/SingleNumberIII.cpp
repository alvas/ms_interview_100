#include <iostream>
#include <unordered_set>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size(), x= 0, a = 0, b = 0;

        for (int i = 0; i < n; ++i)
        {
            x ^= nums[i];
        }

        // x is the last 1 bit of a^b, because a and b is different, there must be
        // one bit that is not the same in a and b.
        x = x - (x & (x - 1));

        for (int i = 0; i < n; ++i)
        {
            // use x to seperate the array into 2 groups
            if (nums[i] & x)
            {
                a ^= nums[i];
            }
            else
            {
                b ^= nums[i];
            }
        }

        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        return v;
    }

    vector<int> singleNumber_using_set(vector<int>& nums) {
        int n = nums.size();
        std::unordered_set<int> s;

        for (int i = 0; i < n; ++i)
        {
            if (s.find(nums[i]) == s.end())
            {
                s.insert(nums[i]);
            }
            else
            {
                s.erase(nums[i]);
            }
        }

        vector<int> v(s.begin(), s.end());
        return v;
    }
};

int main()
{
    Solution sln;
    std::vector<int> nums = {1, 2, 1, 3, 2, 5};
    std::vector<int> v = sln.singleNumber_using_set(nums);
    std::vector<int> v2 = sln.singleNumber(nums);
    printVector<int>(v);
    printVector<int>(v2);
    return 0;
}
