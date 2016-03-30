#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > permute2(vector<int>& nums) {
        vector<vector<int>> r;
        int m = nums.size();

        if (m == 0)
        {
            return r;
        }

        r.push_back(vector<int>(1, nums[0]));

        for (int i = 1; i < m; ++i)
        {
            int n = r.size();

            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < i; ++k)
                {
                    // This location is important. It would not modify the r[j] here. But r[j] would be modified outside of this loop.
                    vector<int> t1 = r[j]; 

                    // use insert, not assign here.
                    t1.insert(t1.begin() + k, nums[i]);

                    // be careful the location of this
                    r.push_back(t1);
                }

                r[j].push_back(nums[i]);
            }
        }

        return r;
    }

    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > r;
        vector<bool> used(nums.size(), false);
        vector<int> per;
        backtrack(nums, per, used, r);
        return r;
    }

    void backtrack(const vector<int> &nums, vector<int> &per, vector<bool> &used, vector<vector<int>> &r)
    {
        int m = nums.size();

        if (per.size() == m)
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

            used[i] = true;
            per.push_back(nums[i]);
            backtrack(nums, per, used, r);
            per.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int> > permute1(vector<int>& nums) {
        vector<vector<int> > r;
        compute(nums, 0, r);
        return r;
    }

    void compute(vector<int> &nums, int start, vector<vector<int> > &r)
    {
        int size = nums.size();

        if (start == size)
        {
            r.push_back(nums);
            return;
        }

        for (int i = start; i < size; ++i)
        {
            swap(nums[start], nums[i]);
            compute(nums, start + 1, r);
            swap(nums[start], nums[i]);
        }
    }
};

int main()
{
    Solution sln;

    const int n = 4;
    int a = 1;
    std::vector<int> nums(n, 0);
    std::generate(nums.begin(), nums.end(), [&a](){ return a++; });

    vector<vector<int> > v = sln.permute(nums);
    print2DVector<int>(v);
    std::cout << "size: " << v.size() << endl;
    return 0;
}
