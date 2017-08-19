#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            // be careful about the negative nums[i].
            int a = abs(nums[i]);

            if (nums[a - 1] > 0) {
                nums[a - 1] *= -1;
            }
            else
            {
                res.push_back(a);
            }
        }
        //unsigned long long a = 0;

        //for (int i = 0; i < nums.size(); ++i) {
            //if ((a & (1ull << (nums[i] - 1))) != 0) {
                //res.push_back(nums[i]);
            //}

            //a |= 1ull << (nums[i] - 1);
        //}

        return res;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {4,3,2,7,8,2,3,1};
    //vector<int> nums = {39,31,8,14,14,38,5,15,29,49,18,6,30,47,8,35,2,17,6,10,29,46,41,48,1,36,5,28,46,39,7,47,18,42,17,11,36,45,21,33,24,10,24,50,25,16,9,12,11,25};
    vector<int> nums = {13,98,15,75,16,49,25,10,62,1,8,49,7,25,79,67,81,93,62,83,61,46,17,50,29,27,3,24,41,35,69,34,28,12,18,46,72,64,2,64,11,17,48,52,95,89,19,40,83,24,82,32,84,88,66,39,54,61,36,9,30,88,16,52,81,80,22,37,44,85,35,60,22,70,34,54,63,8,60,92,2,20,40,50,96,70,10,98,66,51,6,65,97,67,57,9,27,82,63,59};
    vector<int> res = sln.findDuplicates(nums);
    printVector<int>(res);
    return 0;
}
