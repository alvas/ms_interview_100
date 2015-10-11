#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int max = INT_MIN;

        // The initial position is the first index, if there is only one element, then it must be true.
        if (size <= 1)
        {
            return true;
        }

        for (int i = 0; i < size; ++i)
        {
            int tmp = i + nums[i];
            max = max < tmp ? tmp : max;

            // if in the middle, the max can only reach that position and the interger is 0, then it can't go over this position any more.
            if (nums[i] == 0 && max <= i)
            {
                return false;
            }
            // When it is over the end of the array, it can reach the end.
            else if (size - 1 <= max)
            {
                return true;
            }
        }

        return size - 1 <= max;
    }

    bool canJump_slow(vector<int>& nums) {
        int size = nums.size();
        vector<bool> v(size, false);
        
        if (size > 0)
        {
            v[0] = true;
        }
        else
        {
            return false;
        }

        for (int i = 0; i < size; ++i)
        {
            if (v[i] == false)
            {
                continue;
            }

            int steps = nums[i];

            // Be careful about the index here.
            for (int j = 1; j <= steps; ++j)
            {
                // Be careful about behind the boundery.
                if (i + j < size)
                {
                    v[i + j] = true;
                }
            }
        }

        return v[size - 1];
    }
};

int main()
{
    Solution sln;
    //vector<int> a = {2, 0, 0};
    //vector<int> a = {2, 3, 1, 1, 4};
    vector<int> a = {3, 2, 1, 0, 4};
    vector<int> nums(a, a + SIZE(a));
    cout << sln.canJump_slow(nums) << endl;
    cout << sln.canJump(nums) << endl;
    return 0;
}
