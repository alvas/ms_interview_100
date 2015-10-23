#include <iostream>
#include <vector>

using namespace std;

const int LENGTH = 13;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (auto i : nums)
        {
            res ^= i;
        }

        return res;

        //int val = 0;
        //int size = nums.size();

        //for (int i = 0; i < size; ++i)
        //{
            //val ^= nums[i];
        //}

        //return val;
    }
};

int main()
{
    Solution sln;
    int a[LENGTH] = {1, 1, 2, 2, 9, 3, 3, 4, 4, 5, 5, 6, 6};
    vector<int> nums(a, a + LENGTH);
    std::cout << sln.singleNumber(nums) << endl;
    return 0;
}
