#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int sz = nums.size();

        if (sz < 3) {
            return false;
        }

        int minV = nums[0], minV2 = INT_MAX;

        for (int i = 1; i < sz; ++i) {
            if (minV2 < nums[i]) {
                return true;
            }

            // Be careful about the condition here.
            if (nums[i] < minV) {
                minV = nums[i];
            }
            else if (nums[i] < minV2 && minV < nums[i]) {
                minV2 = nums[i];
            }
        }

        return false;
    }
};

int main() {
    Solution sln;
    //vector<int> nums = {1, 2, 3, 4, 5};
    //vector<int> nums = {5, 4, 3, 2, 1};
    //vector<int> nums = {6, 7, 4, 5, 1, 2};
    //vector<int> nums = {5, 5, 1, 5, 5, 2, 5, 4};
    //vector<int> nums = {2, 1, 5, 0, 3};
    vector<int> nums = {1, 1, -2 , 6};
    cout << sln.increasingTriplet(nums) << endl;
    return 0;
}
