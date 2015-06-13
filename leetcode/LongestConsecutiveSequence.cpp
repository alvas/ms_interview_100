#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0, size = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i < size; ++i)
        {
            m[nums[i]] = i;
        }

        vector<int> length(size, 0);

        for (int i = 0; i < size; ++i)
        {
            if (length[i] > 0)
            {
                continue;
            }
            else
            {
                length[i] = consecutiveLength(nums[i], m, length);

                max = max < length[i] ? length[i] : max;
            }
        }

        return max;
    }

    // can't declare m as const unordered_map<int, int> &m, otherwise, compile error
    // "no viable overloaded operator[] for type const unordered_map<int, int>"
    int consecutiveLength(int num, unordered_map<int, int> &m, vector<int> &length)
    {
        if (m.find(num) == m.end())
        {
            return 0;
        }

        int index = m[num];

        if (length[index] > 0)
        {
            return length[index];
        }
        else
        {
            length[index] = consecutiveLength(num - 1, m, length) + 1;
            return length[index];
        }
    }

    int longestConsecutive_use_set(vector<int>& nums) {
        int max = 0, size = nums.size();
        unordered_set<int> s;

        for (int i = 0; i < size; ++i)
        {
            s.insert(nums[i]);
        }

        unordered_set<int> visitedSet;

        for (int i = 0; i < size; ++i)
        {
            if (visitedSet.find(nums[i]) != visitedSet.end())
            {
                continue;
            }
            else
            {
                visitedSet.insert(nums[i]);
                int val = nums[i];
                int len = 1;

                while (s.find(--val) != s.end())
                {
                    len++;
                    visitedSet.insert(val);
                }

                val = nums[i];

                while (s.find(++val) != s.end())
                {
                    len++;
                    visitedSet.insert(val);
                }

                max = max < len ? len : max;
            }
        }

        return max;
    }

    int longestConsecutive_not_qualify(vector<int>& nums) {
        int max = 1;
        sort(nums.begin(), nums.end());
        unique(nums.begin(), nums.end());

        int len = 1, size = nums.size();

        for (int i = 0; i < size - 1; ++i)
        {
            if (nums[i] + 1 == nums[i + 1])
            {
                len++;
                max = max < len ? len : max;
            }
            else
            {
                len = 1;
            }
        }

        return max;
    }
};

int main()
{
    Solution sln;
    //int a[] = {1, 2, 0, 1};
    //int a[] = {100, 4, 200, 1, 3, 2};
    int a[] = {100, 4, 10, 9, 7, 200, 1, 3, 11, 12, 8, 2};
    vector<int> nums(a, a + SIZE(a));
    cout << sln.longestConsecutive(nums) << endl;
    return 0;
}
