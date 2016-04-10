#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int size = nums.size();

        for (int i = 0; i < size; ++i)
        {
            if (s.find(nums[i]) != s.end())
            {
                return true;
            }

            s.insert(nums[i]);
        }

        return false;
    }
};

int main()
{
    Solution sln;
    //vector<int> nums = {1, 2};
    //vector<int> nums = {1, 1};
    //vector<int> nums = {1, 2, 3};
    vector<int> nums = {1, 2, 2, 3};
    std::cout << sln.containsDuplicate(nums) << endl;
    return 0;
}
