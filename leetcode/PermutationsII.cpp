#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Sorry, I am totally cheating. I am using std::next_permutation().
    vector<vector<int> > permuteUnique(vector<int>& nums) {
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
    //vector<int> a = {1, 1, 1};
    //vector<int> a = {1, 1, 2};
    vector<int> a = {3, 3, 0, 0, 2, 3, 2};
    vector<int> nums(a, a + SIZE(a));;
    vector<vector<int> > v = sln.permuteUnique(nums);
    print2DVector<int>(v);
    return 0;
}
