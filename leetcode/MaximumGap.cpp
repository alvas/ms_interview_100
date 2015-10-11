#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int gap = 0;
        int sz = nums.size();

        if (sz <= 1)
        {
            return gap;
        }

        vector<int>::iterator maxItr = max_element(nums.begin(), nums.end());
        vector<int>::iterator minItr = min_element(nums.begin(), nums.end());
        int maxV = *maxItr, minV = *minItr;

        // len is the length of each bucket.
        // Be very careful about the len and the size of buckets.
        int len = (maxV - minV) / sz + 1;
        // number of buckets (maxV - minV) / len + 1
        // each bucket holds a local max and min
        vector<vector<int> >  buckets((maxV - minV) / len + 1);

        for (int i = 0; i < sz; ++i)
        {
            int j = (nums[i] - minV) / len;

            // Don't initialzie the vector, so we can use empty to distinguish the initialized status.
            if (buckets[j].empty())
            {
                buckets[j].reserve(2);
                buckets[j].push_back(nums[i]);
                buckets[j].push_back(nums[i]);
            }
            else
            {
                if (nums[i] < buckets[j][0])
                {
                    buckets[j][0] = nums[i];
                }
                else if (nums[i] > buckets[j][1])
                {
                    buckets[j][1] = nums[i];
                }
            }
        }

        int prev = 0;

        for (int i = 1; i < buckets.size(); ++i)
        {
            // Be careful about the buckets[i], not buckets.
            if (buckets[i].empty())
            {
                continue;
            }

            gap = max(gap, buckets[i][0] - buckets[prev][1]);
            prev = i;
        }

        return gap;
    }

    // radix sort, but not liner space
    int maximumGap_radix_sort(vector<int>& nums) {
        int gap = 0;
        int sz = nums.size();

        if (sz <= 1)
        {
            return gap;
        }

        int maxV = *max_element(nums.begin(), nums.end());

        for (int i = 1; maxV / i > 0; i *= 10)
        {
            countSort(nums, i);
        }

        for (int i = 1; i < sz; ++i)
        {
            gap = max(gap, nums[i] - nums[i - 1]);
        }
        
        return gap;
    }

    void countSort(vector<int> &nums, int j)
    {
        int sz = nums.size();
        vector<int> output(sz, 0);
        vector<int> count(10, 0);

        // Be very careful all % 10 in this funciton.
        for (int i = 0; i < sz; ++i)
        {
            count[(nums[i] / j) % 10]++;
        }

        for (int i = 1; i < 10; ++i)
        {
            count[i] += count[i - 1];
        }

        // Be careful here, i starts from sz - 1 to 0, because count is calculated from 0 to sz
        for (int i = sz - 1; i >= 0; --i)
        {
            output[count[(nums[i] / j) % 10] - 1] = nums[i];
            count[(nums[i] / j) % 10]--;
        }

        for (int i = 0; i < sz; ++i)
        {
            nums[i] = output[i];
        }
    }

    int maximumGap_sort(vector<int>& nums) {
        int gap = 0;
        int sz = nums.size();

        if (sz <= 1)
        {
            return gap;
        }

        sort(nums.begin(), nums.end());

        for (int i = 1; i < sz; ++i)
        {
            gap = max(gap, abs(nums[i] - nums[i - 1]));
        }

        return gap;
    }
};

int main()
{
    Solution sln;
    //vector<int> a = {3, 6, 9, 1};
    //vector<int> nums(a, a + size(a));
    const int LEN = 30;
    vector<int> nums;
    initializeRandomVector(nums, rand() % LEN);
    printVector<int>(nums);
    //cout << sln.maximumGap_sort(nums) << endl;
    cout << sln.maximumGap(nums) << endl;
    cout << sln.maximumGap_sort(nums) << endl;
    cout << sln.maximumGap_radix_sort(nums) << endl;
    return 0;
}
