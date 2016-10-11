#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int sz = nums.size();

        if (sz == 0) {
            return 0;
        }

    }
};

int main() {
    Solution sln;
    //vector<int> nums = {};
    //vector<int> nums = {3};
    //vector<int> nums = {3, 1};
    //vector<int> nums = {3, 1};
    //vector<int> nums = {3, 1, 5};
    vector<int> nums = {3, 1, 5, 8};
    cout << sln.maxCoins(nums) << endl;
    return 0;
}
