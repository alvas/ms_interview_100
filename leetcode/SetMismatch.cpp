#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            int a = abs(nums[i]);

            if (nums[a - 1] > 0) {
                nums[a - 1] *= -1;
            }
            else {
                res.push_back(a);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {1,2,2,4};
    vector<int> res = sln.findErrorNums(nums);
    printVector<int>(res);
    return 0;
}
