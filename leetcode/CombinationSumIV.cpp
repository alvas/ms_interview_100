#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    }

    int combinationSum4_slow(vector<int>& nums, int target) {
        int count = 0;
        getSum(nums, target, count);
        return count;
    }

    void getSum(vector<int> &nums, int target, int &count) {
        if (target == 0) {
            ++count;
            return;
        }
        else if (target < 0) {
            return;
        }

        int sz = nums.size();

        for (int i = 0; i < sz; ++i) {
            getSum(nums, target - nums[i], count);
        }

        return;
    }
};

int main() {
    Solution sln;
    int target = 36;
    vector<int> nums = {1, 2, 3};
    cout << sln.combinationSum4(nums, target) << endl;
    return 0;
}
