#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // can't use swap approach, because it would create dupicated result for case 0303.
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int>> r;
        std::sort(nums.begin(), nums.end());
        vector<int> per;
        vector<bool> used(nums.size(), false);
        permute(nums, per, used, r);
        return r;
    }

    void permute(vector<int> &nums, vector<int> &per, vector<bool> &used, vector<vector<int>> &r)
    {
        int m = nums.size();

        if (m == per.size())
        {
            r.push_back(per);
            return;
        }

        for (int i = 0; i < m; ++i)
        {
            if (used[i])
            {
                continue;
            }

            // Because we already sort the array, duplicated numbers are ajacent.
            // If we the previous number nums[i - 1] is set to false, it means 
            // we just finished it.
            // As long as we finished the first of multiple same numbers, we would
            // skip the duplicated ones, until we move to a different number.
            // When we permute the first one of duplicate numbers, we would permute
            // all possible configurations.
            if (i > 0 && !used[i - 1] && nums[i] == nums[i - 1])
            {
                continue;
            }

            used[i] = true;
            per.push_back(nums[i]);
            permute(nums, per, used, r);
            per.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int> > permuteUnique1(vector<int>& nums) {
        vector<vector<int> > v;
        int sz = nums.size();

        if (sz == 0)
        {
            return v;
        }

        sort(nums.begin(), nums.end());
        
        // Remember to insert the first configuration.
        v.push_back(nums);

        while (next_permutation(nums.begin(), nums.end()))
        {
            v.push_back(nums);
        }

        return v;
    }

    /* This is wrong.
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
    */
};

int main()
{
    Solution sln;
    std::vector<vector<int>> nums = {/*{1, 1, 1}, {1, 1, 2},*/ {3, 3, 0, 0, 2, 3, 2}/*, {3, 0, 3, 0}*/};

    for (auto a : nums)
    {
        std::vector<vector<int>> v = sln.permuteUnique(a);
        print2DVector<int>(v);
        std::cout << v.size() << std::endl;
        std::cout << std::endl;
    }

    std::cout << factorial<7>::value << std::endl;

    return 0;
}
