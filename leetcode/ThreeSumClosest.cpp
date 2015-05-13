#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 0, size = nums.size(), min = 0;
        sort(nums.begin(), nums.end());
        bool initialized = false;

        for (int i = 0; i < size - 2; ++i)
        {
            int start = i + 1, end = size - 1;

            while (start < end)
            {
                int tmpSum = nums[i] + nums[start] + nums[end];
                int absSum = abs(tmpSum - target);

                // Need to keep the min and the sum
                if (!initialized)
                {
                    min = absSum;
                    sum = tmpSum;
                    initialized = true;
                }
                else if (absSum < min)
                {
                    min = absSum;
                    sum = tmpSum;
                }

                if (tmpSum == target)
                {
                    return target;
                }
                else if (tmpSum < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }

        // return the sum, not min.
        return sum;
    }

    int threeSumClosest_naive(vector<int>& nums, int target) {
        bool initialized = false;
        int sum = 0, size = nums.size(), min = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                for (int k = j + 1; k < size; ++k)
                {
                    int t = nums[i] + nums[j] + nums[k];
                    int diff = abs(t - target);

                    if (!initialized || diff < min)
                    {
                        sum = t;
                        min = diff;
                        initialized = true;
                    }
                }
            }
        }

        return sum;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 8;
    int a[LOCAL_LENGTH] = {-1, -3, 2, 0, 1, -4, 54, -9};
    vector<int> nums(a, a + LOCAL_LENGTH);
    int target = 0;
    cout << "Please enter your target: ";
    cin >> target;
    cout << sln.threeSumClosest(nums, target) << endl;
    cout << sln.threeSumClosest_naive(nums, target) << endl;
    return 0;
}
