#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;

            if (m % 2 == 1)
                m--;

            if (nums[m] != nums[m + 1])
                r = m;
            else 
                l = m + 2;
        }

        return nums[l];
    }

    int singleNonDuplicate2(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0)
            return 0;

        return findDuplicate(nums, 0, sz);
    }

    int findDuplicate(const vector<int> &nums, int l, int r) {
        if (l >= r)
            return nums[l];

        int m = l + (r - l) / 2;

        // analyze the index carefully
        // two kinds of conditions, w is odd/even number
        if (l == m)
            return nums[l]; // this condition is tricky
        else if (m % 2 == 0) {
            if (nums[m - 1] == nums[m])
                return findDuplicate(nums, l, m + 1);
            else
                return findDuplicate(nums, m, r);
        }
        else
        {
            if (nums[m] == nums[m + 1])
                return findDuplicate(nums, l, m);
            else
                return findDuplicate(nums, m, r);
        }
    }

    int singleNonDuplicate1(vector<int>& nums) {
        int res = 0;

        for (auto a: nums) {
            res ^= a;
        }

        return res;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {1,1,2,3,3,4,4,8,8};
    //vector<int> nums = {3,3,7,7,10,11,11};
    //vector<int> nums = {1};
    //vector<int> nums = {1, 1, 2};
    //vector<int> nums = {1, 2, 2};
    //vector<int> nums = {1, 2, 2, 3, 3};
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};
    //vector<int> nums;
    cout << sln.singleNonDuplicate(nums) << endl;
    return 0;
}
