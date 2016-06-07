#include <iterator>
#include <iostream>
#include <set>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> tmp(nums1.begin(), nums1.end());
        set<int> tmp2(nums2.begin(), nums2.end());
        vector<int> res;
        // IMPORTANT: set_intersection requires sorted range, so must use set, NOT unordered_set
        std::set_intersection(tmp.begin(), tmp.end(), tmp2.begin(), tmp2.end(), std::back_inserter(res));
        return res;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
    vector<int> nums1 = {1}, nums2 = {1, 2};
    vector<int> res = sln.intersection(nums1, nums2);
    printVector<int>(res);
    return 0;
}
