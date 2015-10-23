#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> v(sz, 1);

        if (sz == 0 || sz == 1)
        {
            v.push_back(1);
            return v;
        }
        else if (sz == 2)
        {
            std::swap(nums[0], nums[1]);
            return nums;
        }

        v.clear();

        // nums: 1 2 3 4
        // v:    4 3 2 1
        v.assign(nums.rbegin(), nums.rend());

        // nums: 1 1*2 1*2*3 4
        // v:    4 4*3 4*3*2 1
        for (int i = 1; i < sz - 1; ++i)
        {
            nums[i] = nums[i] * nums[i - 1];
            v[i] = v[i] * v[i - 1];
        }

        // nums: 1 1*2 1*2*3 4
        // v:    4 4*3 4*3*2 1*2*3
        v[sz - 1] = nums[sz - 2];

        // nums: 1     1*2   1*2*3 4
        // v:    4*1*2 4*3*1 4*3*2 1*2*3
        for (int i = 0; i < sz - 2; ++i)
        {
            v[i] = v[i] * nums[sz - 3 - i];
        }

        // nums: 1     1*2   1*2*3 4
        // v:    4*3*1 4*1*2 4*3*2 1*2*3
        std::reverse(v.begin(), v.begin() + sz - 2);

        // tmp = 4*3*2
        int tmp = v[sz - 2];
        
        // nums: 1     1*2   1*2*3 4
        // v:          4*3*1 4*1*2 1*2*3
        for (int i = sz - 2; i > 0; --i)
        {
            v[i] = v[i - 1];
        }

        // nums: 1     1*2   1*2*3 4
        // v:    4*3*2 4*3*1 4*1*2 1*2*3
        v[0] = tmp;

        return v;
    }

    vector<int> productExceptSelf1(vector<int>& nums) {
        int sz = nums.size();
        vector<int> v(sz, 1);

        if (sz == 0 || sz == 1)
        {
            v.push_back(1);
            return v;
        }
        else if (sz == 2)
        {
            std::swap(nums[0], nums[1]);
            return nums;
        }

        vector<int> v2(sz, 1), v3(sz, 1);
        v2[0] = nums[0];
        v3[sz - 1] = nums[sz - 1];

        for (int i = 1; i < sz - 1; ++i)
        {
            v2[i] = v2[i - 1] * nums[i];
        }

        for (int i = sz - 2; i >= 0; --i)
        {
            v3[i] = v3[i + 1] * nums[i];
        }

        v[0] = v3[1];
        v[sz - 1] = v2[sz - 2];

        for (int i = 1; i < sz - 1; ++i)
        {
            v[i] = v2[i - 1] * v3[i + 1];
        }

        return v;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> v1 = sln.productExceptSelf1(nums);
    printVector<int>(v1);
    vector<int> v = sln.productExceptSelf(nums);
    printVector<int>(v);
    return 0;
}
