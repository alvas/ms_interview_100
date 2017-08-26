#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        
        if (nums.empty()) {
            if (lower == upper) {
                ans.push_back(to_string(lower));
            }
            else {
                ans.push_back(to_string(lower) + "->" + to_string(upper));
            }
            return ans;
        }


        vector<long long> nums2;
        nums2.push_back((long long)lower - 1);
        nums2.insert(nums2.end(), nums.begin(), nums.end());
        nums2.push_back((long long)upper + 1);

        for (int i = 1; i < nums2.size(); ++i)
        {
            long long a = nums2[i], b = nums2[i - 1];

            if (a - 1 <= b) {
                // do nothing
            }
            else if (a == b + 2) {
                ans.push_back(to_string(a - 1));
            }
            else {
                ans.push_back(to_string(b + 1) + "->" + to_string(a - 1));
            }
        }

        return ans;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {0, 1, 3, 50, 75};
    //int lower = 0, upper= 99;
    //vector<int> nums;
    //int lower = 1, upper = 98;
    vector<int> nums = {2147483647}; 
    int lower = -2147483648, upper = 2147483647;
    vector<string> ans = sln.findMissingRanges(nums, lower, upper);
    printVector<string>(ans);
    return 0;
}
