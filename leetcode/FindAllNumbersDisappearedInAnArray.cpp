#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        int sz = nums.size();

        for (int i = 0; i < sz; ++i) {
            int index = nums[i];

            if (nums[abs(index) - 1] > 0) {
                nums[abs(index) - 1] *= -1;
            }
        }

        vector<int> res;

        for (int i = 0; i < sz; ++i) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz);

        for (int i = 0; i < sz; ++i) {
            res[i] = i + 1;
        }

        for (int i = 0; i < sz; ++i) {
            res[nums[i] - 1] = 0;
        }

        int s = 0, e = 0;

        while (e < sz) {
            if (res[e] == 0) {
                e++;
            }
            else {
                res[s++] = res[e++];
            }
        }

        res.resize(s++);

        return res;
    }
};

int main() {
    Solution sln;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> a = sln.findDisappearedNumbers(nums);
    printVector<int>(a);
    return 0;
}
