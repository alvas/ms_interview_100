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
    const int LOCAL_LENGTH = 4;
    //int a[LOCAL_LENGTH] = {1, 2};
    //int a[LOCAL_LENGTH] = {1, 1};
    //int a[LOCAL_LENGTH] = {1, 2, 3};
    int a[LOCAL_LENGTH] = {1, 2, 2, 3};
    vector<int> nums(a, a + LOCAL_LENGTH);
    cout << sln.containsDuplicate(nums) << endl;
    return 0;
}
