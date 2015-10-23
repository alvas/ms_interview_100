#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r && nums[l] >= nums[r])
        {
            int m = (l + r) / 2;

            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        return nums[l];
    }

    int findMin1(vector<int>& nums) {
        int size = nums.size();
        return searchMin(nums, 0, size);
    }

    int searchMin(const vector<int> &nums, int s, int e)
    {
        if (s == e - 1)
        {
            return nums[s];
        }
        else if (s == e - 2)
        {
            return nums[s] < nums[s + 1] ? nums[s] : nums[s + 1];
        }

        int m = (s + e) / 2; 
        int leftMin = (s == m) ? nums[s] : searchMin(nums, s, m);
        int rightMin = (m == e) ? nums[e] : searchMin(nums, m, e);
        return leftMin < rightMin ? leftMin : rightMin;
    }

    // Be very very careful about the conditions.
    int findMin_complicated(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
        {
            return 0;
        }

        int l = 0, r = size;
        int min = nums[l];
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
            if ((nums[0] > nums[1] && (nums[1] > nums[2] || nums[0] < nums[2])) ||
                (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] < nums[2]))
            {
                increasing = false;
            }
        }

        while (l < r)
        {
            int m = (l + r) / 2;

            if (increasing)
            {
                // Whenever there are only 2 elements left, the equal condition is improtant.
                if (nums[l] <= nums[m] && nums[m] <= nums[r - 1])
                {
                    min =  nums[l];
                    break;
                }
                else if (nums[l] >= nums[m] && nums[m] >= nums[r - 1])
                {
                    min = nums[r - 1];
                    break;
                }
                else if (nums[l] < nums[m] && nums[m] > nums[r - 1])
                {
                    // don't include nums[m]
                    l = m + 1;
                }
                else if (nums[l] > nums[m] && nums[m] < nums[r - 1])
                {
                    // include nums[m]
                    r = m + 1;
                }
            }
            else
            {
                // Whenever there are only 2 elements left, the equal condition is improtant.
                if (nums[l] <= nums[m] && nums[m] <= nums[r - 1])
                {
                    min =  nums[l];
                    break;
                }
                else if (nums[l] >= nums[m] && nums[m] >= nums[r - 1])
                {
                    min = nums[r - 1];
                    break;
                }
                else if (nums[l] > nums[m] && nums[m] < nums[r - 1])
                {
                    // include nums[m]
                    l = m;
                }
                else if (nums[l] < nums[m] && nums[m] > nums[r - 1])
                {
                    // don't include nums[m]
                    r = m;
                }
            }
        }

        return min;
    }

    int findMin_naive(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
        {
            return 0;
        }

        int min = nums[0];

        for (int i = 1; i < size; ++i)
        {
            if (nums[i] < min)
            {
                min = nums[i];
            }
        }

        return min;
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

    int a2_1[2] = {2, 1};
    v1.assign(a2_1, a2_1 + 2);
    v.push_back(v1);

    int a3[3] = {1, 2, 3};
    v1.assign(a3, a3 + 3);
    v.push_back(v1);

    int a3_1[3] = {1, 3, 2};
    v1.assign(a3_1, a3_1 + 3);
    v.push_back(v1);

    int a3_2[3] = {2, 1, 3};
    v1.assign(a3_2, a3_2 + 3);
    v.push_back(v1);

    int a3_3[3] = {2, 3, 1};
    v1.assign(a3_3, a3_3 + 3);
    v.push_back(v1);

    int a3_4[3] = {3, 1, 2};
    v1.assign(a3_4, a3_4 + 3);
    v.push_back(v1);

    int a3_5[3] = {3, 2, 1};
    v1.assign(a3_5, a3_5 + 3);
    v.push_back(v1);

    int a4[4] = {1, 2, 3, 4};
    v1.assign(a4, a4 + 4);
    v.push_back(v1);

    int a4_1[4] = {2, 3, 4, 1};
    v1.assign(a4_1, a4_1 + 4);
    v.push_back(v1);

    int a4_2[4] = {3, 4, 1, 2};
    v1.assign(a4_2, a4_2 + 4);
    v.push_back(v1);

    int a4_3[4] = {4, 1, 2, 3};
    v1.assign(a4_3, a4_3 + 4);
    v.push_back(v1);

    int a4_4[4] = {4, 3, 2, 1};
    v1.assign(a4_4, a4_4 + 4);
    v.push_back(v1);

    int a4_5[4] = {3, 2, 1, 4};
    v1.assign(a4_5, a4_5 + 4);
    v.push_back(v1);

    int a4_6[4] = {2, 1, 4, 3};
    v1.assign(a4_6, a4_6 + 4);
    v.push_back(v1);

    int a4_7[4] = {1, 4, 3, 2};
    v1.assign(a4_7, a4_7 + 4);
    v.push_back(v1);

    int a5[5] = {1, 2, 3, 4, 5};
    v1.assign(a5, a5 + 5);
    v.push_back(v1);

    int a5_1[5] = {2, 3, 4, 5, 1};
    v1.assign(a5_1, a5_1 + 5);
    v.push_back(v1);

    int a5_2[5] = {3, 4, 5, 1, 2};
    v1.assign(a5_2, a5_2 + 5);
    v.push_back(v1);

    int a5_3[5] = {4, 5, 1, 2, 3};
    v1.assign(a5_3, a5_3 + 5);
    v.push_back(v1);

    int a5_4[5] = {5, 1, 2, 3, 4};
    v1.assign(a5_4, a5_4 + 5);
    v.push_back(v1);

    int a7[7] = {4, 5, 6, 7, 0, 1, 2};
    v1.assign(a7, a7 + 7);
    v.push_back(v1);

    for (vector<vector<int> >::iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        printVector<int>(*itr);
        //std::cout << sln.findMin_complicated(*itr) << endl << endl;
        std::cout << sln.findMin(*itr) << endl << endl;
    }

    return 0;
}
