#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
        {
            return 0;
        }

        int ret = 0;

        for (int i = 0; i <= n; ++i)
        {
            ret ^= i;
        }

        for (int &i : nums)
        {
            ret ^= i;
        }

        return ret;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {0, 1, 3};
    std::cout << sln.missingNumber(nums) << endl;
    return 0;
}
