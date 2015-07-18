#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    }
};

int main()
{
    Solution sln;
    int a[] = {1, 2, 3};
    vector<int> nums(a, a + SIZE(a));
    printVector<int>(nums);
    int k = 0;
    cout << "Please enter k: ";
    cin >> k;
    vector<int> v = sln.maxSlidingWindow(nums, k);
    printVector<int>(v);
    return 0;
}
