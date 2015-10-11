#include <iostream> 
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz = nums.size();

        if (sz == 0)
        {
            return 0;
        }

        int sum = 0;
        int start = 0, end = 0;

        // Be careful to set the initial value. If we use 0 here, then min() would alway get 0 and may be a wrong answer.
        int minV = sz + 1;

        while (end < sz)
        {
            while (start < sz && sum < s)
            {
                sum += nums[start++];
            }

            // Be careful about the len = start - end.
            if (sum >= s)
            {
                minV = min(minV, start - end);
            }

            while (end < start && sum >= s)
            {
                sum -= nums[end++];

                // Be careful about the len = start - end.
                if (sum >= s)
                {
                    minV = min(minV, start - end);
                }
            }

            if (start >= sz)
            {
                break;
            }
        }

        if (minV == sz + 1)
        {
            minV = 0;
        }

        return minV;
    }
};

int main()
{
    Solution sln;
    vector<int> a = {2, 3, 1, 2, 4, 3, 6};
    vector<int> nums(a, a + SIZE(a));
    cout << "Please enter s:";
    int s = 0;
    cin >> s;
    cout << sln.minSubArrayLen(s, nums) << endl;
    return 0;
}
