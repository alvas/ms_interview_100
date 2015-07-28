#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int sz = nums.size();

        if (sz == 0)
        {
            return result;
        }

        string s;

        for (int i = 0; i < sz; ++i)
        {
            int j = i;

            while (j + 1 < sz && nums[j] + 1 == nums[j + 1])
            {
                ++j;
            }

            if (i == j)
            {
                // use to_string instead of itoa
                s = to_string(nums[i]);
            }
            else
            {
                s = to_string(nums[i]) + "->" + to_string(nums[j]);
            }

            result.push_back(s);

            i = j;
        }

        return result;
    }
};

int main()
{
    Solution sln;
    int a[] = {0, 1, 2, 4, 5 , 7};
    vector<int> nums(a, a + SIZE(a));
    vector<string> v = sln.summaryRanges(nums);
    printVector<string>(v);
    return 0;
}
