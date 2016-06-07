#include <iostream>
#include <map>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> m1, m2;

        for (auto n : nums1)
        {
            if (m1.find(n) == m1.end())
            {
                m1[n] = 1;
            }
            else
            {
                m1[n]++;
            }
        }

        for (auto n : nums2)
        {
            if (m2.find(n) == m2.end())
            {
                m2[n] = 1;
            }
            else
            {
                m2[n]++;
            }
        }

        for (auto itr = m1.begin(); itr != m1.end(); ++itr)
        {
            int n = itr->first;
            auto itr2 = m2.find(n);

            if (itr2 != m2.end())
            {
                res.insert(res.end(), min(itr->second, itr2->second), n);
            }
        }

        return res;
    }
};

int main()
{
    Solution sln;
    vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
    //vector<int> nums1 = {1}, nums2 = {1, 2};
    vector<int> res = sln.intersect(nums1, nums2);
    printVector<int>(res);
    return 0;
}
