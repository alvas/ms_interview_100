#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1) {
            return false;
        }

        sum /= 2;

        return getSum(nums, 0, sum);
    }

    bool getSum(vector<int>& nums, int b, int target) {
        if (target == 0) {
            return true;
        }
        else if (target < 0) {
            return false;
        }

        int sz = nums.size();

        for (int i = b; i < sz; ++i) {
            if (getSum(nums, i + 1, target - nums[i])) {
                return true;
            }
        }

        return false;
    }

    bool canPartition_slow(vector<int>& nums) {
        int l = 0, r = 0;
        return divideArray(nums, 0, l, r);
    }

    bool divideArray(vector<int>& nums, int idx, int l, int r) {
        int sz = nums.size();

        if (idx == sz) {
            return l == r;
        }

        bool res = (divideArray(nums, idx + 1, l + nums[idx], r) || 
                   divideArray(nums, idx + 1, l, r + nums[idx])); 

        return res;
    }
};

int main() {
    Solution sln;
    vector<int> nums = {1, 5, 11, 5};
    //vector<int> nums = {1, 2, 3, 5};
    //vector<int> nums = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
    //cout << sln.canPartition_slow(nums) << endl;
    cout << sln.canPartition(nums) << endl;
    return 0;
}
