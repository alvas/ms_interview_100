#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // algorithm borrowed from STL
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();

        if (sz == 0 || sz == 1)
        {
            return;
        }

        int i = sz - 1;

        for ( ; ; )
        {
            int ii = i;
            --i;

            if (nums[i] < nums[ii])
            {
                int j = sz;

                while (!(nums[i] < nums[--j]))
                {
                    ;
                }

                swap(nums[i], nums[j]);
                reverse(nums.begin() + ii, nums.end());
                return;
            }

            if (i == 0)
            {
                reverse(nums.begin(), nums.end());
                return;
            }
        }
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {1, 2, 3};
    printVector<int>(nums);
    //next_permutation(nums.begin(), nums.end());
    sln.nextPermutation(nums);
    printVector<int>(nums);
    return 0;
}
