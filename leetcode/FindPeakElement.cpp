#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peak = 0;
        return peak;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 9;
    vector<int> nums;
    initializeRandomVector(nums, LOCAL_LENGTH);
    printVector<int>(nums);
    cout << sln.findPeakElement(nums) << endl;
    return 0;
}
