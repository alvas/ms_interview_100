#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    }
};

int main() {
    Solution sln;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> a = sln.findDisappearedNumbers(nums);
    printVector<int>(a);
    return 0;
}
