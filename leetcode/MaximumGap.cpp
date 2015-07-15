#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int gap = 0;
        int sz = nums.size();

        if (sz <= 1)
        {
            return gap;
        }

        return gap;
    }
};

int main()
{
    Solution sln;
    //int a[] = {};
    //vector<int> nums(a, a + SIZE(a));
    const int LEN = 30;
    vector<int> nums;
    initializeRandomVector(nums, rand() % LEN);
    printVector<int>(nums);
    cout << sln.maximumGap(nums) << endl;
    return 0;
}
