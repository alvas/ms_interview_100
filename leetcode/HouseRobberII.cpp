#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int money = 0;
        int sz = nums.size();

        if (sz == 0)
        {
            return money;
        }

        return money;
    }
};

int main()
{
    Solution sln;
    const int LEN = 17;
    vector<int> nums;
    initializeRandomVector(nums, LEN);
    printVector<int>(nums);

    //for (auto n : nums)
    //{
        //cout << n << "\t";
    //}
    
    //cout << endl;
    
    cout << sln.rob(nums) << endl;
    return 0;
}
