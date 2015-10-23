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

            if (nums[l] > nums[r])
            {
                l = m + 1;
            }
            else if (nums[m] < nums[l])
            {
                r = m;
            }
            // nums[l] == nums[m] == nums[r]
            else
            {
                l = l + 1;
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

    for (vector<vector<int> >::iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        printVector<int>(*itr);
        //std::cout << sln.findMin_complicated(*itr) << endl << endl;
        std::cout << sln.findMin(*itr) << endl << endl;
    }

    return 0;
}
