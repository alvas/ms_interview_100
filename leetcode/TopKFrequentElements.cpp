#include <iostream>
#include <queue>
#include <vector>
#include <map>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Need to improve.
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> r;

        if (k >= n)
        {
            return nums;
        }
        else if (k <= 0)
        {
            return r;
        }

        map<int, int> m;

        for (auto a: nums)
        {
            if (m.find(a) == m.end())
            {
                m[a] = 1;
            }
            else
            {
                m[a]++;
            }
        }

        multimap<int, int> mm;

        for (auto b:m)
        {
            mm.emplace(b.second, b.first);
        }

        for (auto ritr = mm.rbegin(); ritr != mm.rend(); ++ritr)
        {
            r.push_back(ritr->second);

            if (--k == 0)
            {
                break;
            }
        }

        return r;
    }
};

int main()
{
    Solution sln;
    vector<int> nums = {1, 1, 1, 2, 2, 3, 3};
    int k = 2;
    vector<int> r = sln.topKFrequent(nums, k);
    printVector<int>(r);
    return 0;
}
