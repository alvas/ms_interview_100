#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int sz = nums.size();

        if (sz <= 1) {
            return;
        }

        for (int i = 1; i < sz; ++i) {
            if (((i % 2) == 1 && nums[i] < nums[i - 1]) || ((i % 2) == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }

    void wiggleSort1(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sz = nums.size();

        for (int i = 1; i < sz; i += 2) {
            if (i + 1 < sz) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
};

int main() {
    Solution sln;
    vector<int> nums = {3, 5, 2, 1, 6, 4};
    sln.wiggleSort(nums);
    printVector<int>(nums);
    return 0;
}
