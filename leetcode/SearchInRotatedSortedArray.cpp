#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;

        while (s <= e)
        {
            int m = s + (e - s) / 2;

            if (nums[m] == target)
            {
                return m;
            }

            // It is comparing the m and e here, not m and target.
            if (nums[m] < nums[e])
            {
                if (target > nums[m] && target <= nums[e])
                {
                    s = m + 1;
                }
                else
                {
                    e = m - 1;
                }
            }
            else
            {
                if (target >= nums[s] && target < nums[m])
                {
                    e = m - 1;
                }
                else
                {
                    s = m + 1;
                }
            }
        }

        return -1;
    }

    int search1(vector<int>& nums, int target) {
        int size = nums.size();
        return searchTarget(nums, 0, size, target);
    }

    int searchTarget(const vector<int> &nums, int s, int e, int target)
    {
        if (s >= e)
        {
            return -1;
        }
        else if (s == e - 1)
        {
            if (nums[s] == target)
            {
                return s;
            }
            else
            {
                return -1;
            }
        }

        int m = (s + e) / 2;
        int r = searchTarget(nums, s, m, target);

        if (r != -1)
        {
            return r;
        }
        else
        {
            return searchTarget(nums, m, e, target);
        }
    }

    int search_complicated(vector<int>& nums, int target) {
        int size = nums.size();

        if (size == 0)
        {
            return -1;
        }

        int l = 0, r = size;
        bool increasing = true;
        
        if (size < 3)
        {
            if (nums[l] > nums[r - 1])
            {
                increasing = false;
            }
        }
        else
        {
            if (nums[0] > nums[1] && (nums[1] > nums[2] || nums[0] < nums[2]))
            {
                increasing = false;
            }
        }

        while (l < r)
        {
            int m = (l + r) / 2;

            if (nums[l] == target)
            {
                return l;
            }
            else if (nums[r - 1] == target)
            {
                return r - 1;
            }
            else if (nums[m] == target)
            {
                return m;
            }

            if (increasing)
            {
                // When there are only two element left, the increasing would reverse.
                if (nums[l] <= nums[m] && nums[m] <= nums[r - 1])
                {
                    if (nums[m] < target)
                    {
                        l = m + 1;
                    }
                    else
                    {
                        r = m;
                    }
                }
                else if (nums[l] >= nums[m] && nums[m] >= nums[r - 1])
                {
                    if (nums[m] < target)
                    {
                        r = m;
                    }
                    else
                    {
                        l = m + 1;
                    }
                }
                else if (nums[l] < nums[m] && nums[m] > nums[r - 1])
                {
                    if (nums[l] < target && target < nums[m])
                    {
                        r = m;
                    }
                    else if (nums[l] > target && target > nums[r - 1])
                    {
                        break;
                    }
                    else if (nums[m] < target || target < nums[l])
                    {
                        l = m + 1;
                    }
                }
                else if (nums[l] > nums[m] && nums[m] < nums[r - 1])
                {
                    if (nums[m] < target && target < nums[r - 1])
                    {
                        l = m + 1;
                    }
                    else if (target < nums[m] || nums[l] < target)
                    {
                        r = m;
                    }
                    else if (target < nums[l] && nums[r - 1] < target)
                    {
                        break;
                    }
                }
            }
            else
            {
                if (nums[l] >= nums[m] && nums[m] >= nums[r - 1])
                {
                    if (nums[m] < target)
                    {
                        r = m;
                    }
                    else
                    {
                        l = m + 1;
                    }
                }
                else if (nums[l] <= nums[m] && nums[m] <= nums[r - 1])
                {
                    if (nums[m] < target)
                    {
                        l = m + 1;
                    }
                    else
                    {
                        r = m;
                    }
                }
                else if (nums[l] < nums[m] && nums[m] > nums[r - 1])
                {
                    if (nums[m] > target && target > nums[r - 1])
                    {
                        l = m + 1;
                    }
                    else if (nums[l] < target & target < nums[r - 1])
                    {
                        break;
                    }
                    else if (target > nums[m] || nums[l] > target)
                    {
                        r = m;
                    }
                }
                else if (nums[l] > nums[m] && nums[m] < nums[r - 1])
                {
                    if (nums[l] > target && target > nums[m])
                    {
                        r = m;
                    }
                    else if (target < nums[m] || nums[r - 1] < target)
                    {
                        l = m + 1;
                    }
                    else if (nums[l] < target && target < nums[r - 1])
                    {
                        break;
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution sln;
    vector<vector<int> > v;
    vector<int> v1;

    int a1[1] = {1};
    v1.assign(a1, a1 + 1);
    v.push_back(v1);
    
    int a2[2] = {1, 2};
    v1.assign(a2, a2 + 2);
    v.push_back(v1);

    int a3[2] = {2, 1};
    v1.assign(a3, a3 + 2);
    v.push_back(v1);

    int a4[3] = {1, 2, 3};
    v1.assign(a4, a4 + 3);
    v.push_back(v1);

    int a5[3] = {2, 1, 3};
    v1.assign(a5, a5 + 3);
    v.push_back(v1);

    int a6[3] = {2, 3, 1};
    v1.assign(a6, a6 + 3);
    v.push_back(v1);

    int a7[3] = {3, 1, 2};
    v1.assign(a7, a7 + 3);
    v.push_back(v1);

    int a8[3] = {3, 2, 1};
    v1.assign(a8, a8 + 3);
    v.push_back(v1);

    int a9[4] = {1, 2, 3, 4};
    v1.assign(a9, a9 + 4);
    v.push_back(v1);

    int a10[4] = {4, 3, 2, 1};
    v1.assign(a10, a10 + 4);
    v.push_back(v1);

    int a11[5] = {1, 2, 3, 4, 5};
    v1.assign(a11, a11 + 5);
    v.push_back(v1);

    int a12[5] = {2, 3, 4, 5, 1};
    v1.assign(a12, a12 + 5);
    v.push_back(v1);

    int a13[5] = {3, 4, 5, 1, 2};
    v1.assign(a13, a13 + 5);
    v.push_back(v1);

    int a14[5] = {4, 5, 1, 2, 3};
    v1.assign(a14, a14 + 5);
    v.push_back(v1);

    int a15[5] = {5, 1, 2, 3, 4};
    v1.assign(a15, a15 + 5);
    v.push_back(v1);

    int a16[7] = {4, 5, 6, 7, 0, 1, 2};
    v1.assign(a16, a16 + 7);
    v.push_back(v1);

    int target[9] = {-2, -1, 0, 1, 2, 3, 4, 5, 6};
    vector<int> targets(target, target + 9);

    for (int i = 0; i < 16; ++i)
    {
        printVector<int>(v[i]);

        for (int j = 0; j < 9; ++j)
        {
            std::cout << "Target: " << targets[j] << ", result: " << sln.search(v[i], targets[j]) << endl;
        }
    }

    return 0;
}
