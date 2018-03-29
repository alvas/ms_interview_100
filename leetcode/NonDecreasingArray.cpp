#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int maxV = 

        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                count++;

                if (count > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {4, 2, 3};
    //vector<int> nums = {4, 2, 1};
    vector<int> nums = {3, 4, 2, 3};
    cout << sln.checkPossibility(nums) << endl;
    return 0;
}
