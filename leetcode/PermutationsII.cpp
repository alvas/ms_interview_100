#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > v;
        int sz = nums.size();

        if (sz == 0)
        {
            return v;
        }

        sort(nums.begin(), nums.end());
        permute(nums, v, 0, sz);
        return v;
    }

    void permute(vector<int> &nums, vector<vector<int> > &v, int idx, int sz)
    {
        if (idx >= sz)
        {
            v.push_back(nums);
            return;
        }

        for (int i = idx; i < sz; )
        {
            swap(nums[i], nums[idx]);
            permute(nums, v, idx + 1, sz);
            swap(nums[i], nums[idx]);

            while (++i < sz && nums[idx] == nums[i])
            {
                ;
            }
        }
    }
};

int main()
{
    Solution sln;
    //int a[] = {1, 1, 2};
    int a[] = {3, 3, 0, 0, 2, 3, 2};
    vector<int> nums(a, a + SIZE(a));;
    vector<vector<int> > v = sln.permuteUnique(nums);
    print2DVector<int>(v);
    return 0;
}
