#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;

        if (n == 0)
        {
            return v;
        }

        for (int i = 0; i < n; ++i)
        {
        }

        return v;
    }
};

int main()
{
    Solution sln;
    int a[] = {1, 2, 1, 3, 2, 5};
    vector<int> nums(a, a + SIZE(a));
    vector<int> v = sln.singleNumber(nums);
    printVector<int>(v);
    return 0;
}
