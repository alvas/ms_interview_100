#include <iostream>
#include <vector>
#include "UnitTest++/UnitTest++.h"

using namespace std;

class Solution {
public:
    // Need to improve
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, tmp = 0;

        for (int i : nums) {
            count = max(count, tmp = (i == 0) ? 0 : tmp + 1);
        }

        //for_each(nums.begin(), nums.end(), [&count, &tmp](int i) {
            //if (i == 0) {
                //tmp = 0;
            //}
            //else {
                //tmp++;
                //count = max(count, tmp);
            //}
        //});

        return count;
    }
};

SUITE(MaxConsecutiveOnes)
{
    TEST(case1)
    {
        Solution sln;
        vector<int> nums = {1, 1, 0, 1, 1, 1};
        int result = sln.findMaxConsecutiveOnes(nums);
        cout << result << endl;
        CHECK_EQUAL(3, result);
    }
}
