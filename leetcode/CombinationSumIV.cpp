#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= target; ++i) {
            for (auto a: nums) {
                if (i >= a) {
                    dp[i] += dp[i - a];
                }
            }
        }

        return dp.back();
    }

    int combinationSum4_2(vector<int>& nums, int target) {
        int sz = nums.size();

        if (sz == 0) {
            return 0;
        }

        int len = *max_element(nums.begin(), nums.end());
        len = max(target, len);
        vector<int> v(len + 1, 0);

        for (int i = 0; i < sz; ++i) {
            v[nums[i]]++;
        }

        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < sz; ++j) {
                if (i - nums[j] > 0) {
                    v[i] += v[i - nums[j]];
                }
            }
        }

        // be careful that v.back() may not be v[target], because if the array element is bigger than target
        // v.back() would not be v[target].
        return v[target];
    }

    int combinationSum4_slow2(vector<int>& nums, int target) {
        int sz = nums.size();
        int cnt = 0;
        vector<int> v;

        for (auto a: nums) {
            if (a == target) {
                cnt++;
            }

            v.push_back(a);
        }

        while (!v.empty()) {
            int sz2 = v.size();
            vector<int> tmp;

            for (int j = 0; j < sz2; ++j) {
                for (int i = 0; i < sz; ++i) {
                    int a = v[j] + nums[i];

                    if (a == target) {
                        cnt++;
                    }

                    if (a <= target) {
                        tmp.push_back(a);
                    }
                }
            }

            v.swap(tmp);
        }

        return cnt;
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
    int target = 3;
    //vector<int> nums = {1, 2, 3};
    //vector<int> nums = {};
    vector<int> nums = {9};
    cout << sln.combinationSum4_slow(nums, target) << endl;
    cout << sln.combinationSum4(nums, target) << endl;
    return 0;
}
