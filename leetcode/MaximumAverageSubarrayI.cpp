#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        int sz = nums.size();

        if (sz <= k) {
            sum = accumulate(nums.begin(), nums.end(), sum);
            return sum / k;
        }

        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }

        double maxV = sum;

        for (int i = k; i < sz; ++i) {
            sum = sum - nums[i - k] + nums[i];
            maxV = max(sum, maxV);
        }

        return maxV / k;
    }
};

int main()
{
    Solution sln;
    int k = 4;
    vector<int> nums = {1,12,-5,-6,50,3};
    cout << sln.findMaxAverage(nums, k) << endl;
    return 0;
}
