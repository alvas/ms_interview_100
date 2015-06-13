#include <iostream>
#include <queue>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();

        if (size <= 1)
        {
            return 0;
        }

        int i = 0;
        int max = nums[i++], step = 1;

        if (max >= size - 1)
        {
            return step;
        }

        while (max < size - 1)
        {
            int prevMax = max;

            for ( ; i <= prevMax && i < size; ++i)
            {
                int tmp = i + nums[i];

                if (tmp > max)
                {
                    max = tmp;

                    if (max >= size - 1)
                    {
                        return ++step;
                    }
                }
            }

            ++step;
        }

        return step;
    }

    // Must improve.
    int jump_stupid(vector<int>& nums) {
        int size = nums.size();

        if (size <= 1)
        {
            return 0;
        }

        queue<int> q;
        int max = INT_MIN, step = 0, i = 0;
        q.push(nums[i]);
        step++;

        // Be careful about the situation that the first position can reach the last position.
        if (nums[0] >= size - 1)
        {
            return step;
        }

        i++;

        while (i < size && !q.empty())
        {
            queue<int> tmp;

            while (!q.empty())
            {
                int front = q.front();
                q.pop();

                for ( ; i <= front && i < size; ++i)
                {
                    int pos = nums[i] + i;

                    // When it reaches the last position, remember to add up the last step.
                    if (pos >= size - 1)
                    {
                        return ++step;
                    }

                    if (pos > max)
                    {
                        max = pos;
                        tmp.push(pos);
                    }
                }
            }

            q = tmp;
            step++;
        }

        return step;
    }

    int jump_slow(vector<int>& nums) {
        int size = nums.size();
        vector<int> v(size, 0);

        if (size <= 1)
        {
            return 0;
        }

        for (int i = 0; i < size; ++i)
        {
            int tmp = nums[i];

            for (int j = 1; j <= tmp; ++j)
            {
                if (i + j < size)
                {
                    if (v[i + j] == 0 || v[i + j] > v[i] + 1)
                    {
                        v[i + j] = v[i] + 1;
                    }
                }
            }
        }

        return v[size - 1];
    }
};

int main()
{
    Solution sln;
    //int a[] = {1, 2};
    //int a[] = {2, 0, 0};
    int a[] = {2, 3, 1, 1, 4};
    //int a[] = {3, 2, 1, 0, 4};
    vector<int> nums(a, a + SIZE(a));
    cout << sln.jump_slow(nums) << endl;
    cout << sln.jump(nums) << endl;
    return 0;
}
