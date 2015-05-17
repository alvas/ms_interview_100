#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Could be improved??
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
        {
            return 0;
        }

        int max = nums[0], sum = nums[0];

        for (int i = 1; i < size; ++i)
        {
            // when sum is small than 0, we set the sum to the last negative nums[i]
            // because adding negative number together will make sum smaller and smaller
            // don't need to add any negative to it.
            // WHEN sum is negative, nums[i] is positive, sum is reset to nums[i] which is the first positive after a negative sequence.
            if (sum < 0)
            {
                sum = nums[i];
            }
            else
            {
                // as long as sum is positive, we add nums[i] to sum, because even nums[i] is negative, sum + nums[i] + nums[i + 1] could still bigger than sum, so the continous sum will be bigger.
                sum += nums[i];
            }

            if (max < sum)
            {
                max = sum;
            }
        }

        return max;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 4;
    //int a[LOCAL_LENGTH] = {-2, -1, -3, 4, -1, 2, 1, -5, 4};
    //int a[LOCAL_LENGTH] = {-1};
    //int a[LOCAL_LENGTH] = {-1, -2};
    //int a[LOCAL_LENGTH] = {-2, -1};
    //int a[LOCAL_LENGTH] = {-3, -2, -1};
    //int a[LOCAL_LENGTH] = {-3, -1, -2};
    //int a[LOCAL_LENGTH] = {-2, -3, -1};
    //int a[LOCAL_LENGTH] = {-1, -3, -2};
    int a[LOCAL_LENGTH] = {-1, -3, -2, 2};
    vector<int> v(a, a + LOCAL_LENGTH);
    cout << sln.maxSubArray(v) << endl;
    return 0;
}
