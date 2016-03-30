#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();

        if (sz == 0 || sz == 1)
        {
            return;
        }

        for (int i = sz - 1; i > 0; )
        {
            int j = i - 1;

            if (nums[j] < nums[i])
            {
                int ii = sz;

                // condition here
                while (nums[--ii] < nums[j])
                {
                    ;
                }


                swap(nums[ii], nums[j]);
                reverse(nums.begin() + i, nums.end());
                return;
            }

            --i;

            if (i == 0)
            {
                reverse(nums.begin(), nums.end());
                return;
            }
        }

        return;
    }

    // algorithm borrowed from STL
    void nextPermutation1(vector<int>& nums) {
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
    const int n = 5;
    int a = 1;
    std::vector<int> nums(n, 0);
    std::generate(nums.begin(), nums.end(), [&a](){ return a++; });

    int b = factorial<n>::value;

    for (int i = 0; i < b; ++i)
    {
        printVector<int>(nums);
        //next_permutation(nums.begin(), nums.end());
        sln.nextPermutation(nums);
        printVector<int>(nums);
        std::cout << endl;
    }

    return 0;
}
