#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sz = nums.size();

        if (sz == 0) {
            return 0;
        }

        // output: m
        // final - min = m
        // sum + m * (n - 1) = n * (m + min)
        // m = sum - min * n
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int minV = *min_element(nums.begin(), nums.end());
        return sum - minV * sz;
    }
};

int main() {
    Solution sln;
    vector<int> nums = {1, 2, 3};
    cout << sln.minMoves(nums) << endl;
    return 0;
}
