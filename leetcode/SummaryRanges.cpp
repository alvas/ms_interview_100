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
            while (i + 1 < sz && nums[i] + 1 == nums[i + 1])
            {
                ++i;
            }

            if (i + 1 < sz)
            {
            }
        }

        return result;
    }
};

int main()
{
    Solution sln;
    int a[] = {};
    vector<int> v(a, a + SIZE(a));
    vector<string> v = sln.summaryRanges(nums);
    printVector<string>(v);
    return 0;
}
