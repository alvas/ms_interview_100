#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int arrayPairSum(vector<int>& nums) {
            // We can prove this by swapping any 2 numbers in ascending order array.
            // Any swapping would cause a worser result.
            sort(nums.begin(), nums.end());
            int sz = nums.size(), sum = 0;

            for (int i = 0; i < sz; i += 2) {
                sum += nums[i];
            }

            return sum;
        }

};

int main()
{
    Solution sln;
    vector<int> nums = {1, 4, 3, 2};
    vector<int> nums1;

    for (int i = 1; i < 101; ++i) {
        nums1.push_back(i);
    }

    cout << sln.arrayPairSum(nums) << endl;
    cout << sln.arrayPairSum(nums1) << endl;
    return 0;
}
