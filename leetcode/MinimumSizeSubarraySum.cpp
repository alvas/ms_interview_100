#include <iostream> 
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int minSubArrayLenNlogN(int s, vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        int res = n + 1;

        // sum[i] : sum of nums[0] till nums[i - 1]
        for (int i = 1; i < n + 1; ++i)
        {
            sums[i] = sums[i - 1] + nums[i -1];
        }

        for (int i = 0; i < n + 1; ++i)
        {
            // binary search for sums[right] > sums[i] + s,
            // so sum of nums[i + 1] ... nums[right] > s
            // IMPORTANT!! because all numbers are positive, so sums[] is in ascending order.
            // This is the requirement that we can use binary search.
            int right = searchRight(i + 1, n, sums[i] + s, sums);
            
            if (right == n + 1)
            {
                break;
            }

            res = min(res, right - i);
        }

        return res == n + 1 ? 0 : res;
    }

    int searchRight(int left, int right, int key, vector<int> &sums)
    {
        while (left <= right)
        {
            int m = (left + right) / 2;

            if (sums[m] >= key)
            {
                right = m - 1;
            }
            else
            {
                left = m + 1;
            }
        }

        return left;
    }

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
            // expanding the range on the right
            while (start < sz && sum < s)
            {
                sum += nums[start++];
            }

            // Be careful about the len = start - end.
            if (sum >= s)
            {
                minV = min(minV, start - end);
            }

            // shrinking the range on the left
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


    int minSubArrayLen1(int s, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sum(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i)
        {
            sum[i][i] = nums[i];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j + i < n; ++j)
            {
                sum[j][i + j] = sum[j][i + j - 1] + nums[j];

                if ((sum[j][i + j]) > s)
                {
                    return i;
                }
            }
        }

        return 0;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {2, 3, 1, 2, 4, 3, 6};
    std::cout << "Please enter s:";
    int s = 0;
    cin >> s;
    std::cout << sln.minSubArrayLen(s, nums) << endl;
    return 0;
}
