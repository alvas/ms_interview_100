#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int min = 0, size = nums.size();

        if (size == 0)
        {
            return min;
        }

        int sum = nums[0], start = 0, end = 1;

        while (start < size)
        {
        }

        return min;
    }
};

int main()
{
    Solution sln;
    int s = 0;
    const int LOCAL_LENGTH = 6;
    int a[LOCAL_LENGTH] = {2, 3, 1, 2, 4, 3};
    vector<int> nums(a, a + LOCAL_LENGTH);
    cout << "Please enter s:";
    cin >> s;
    cout << sln.minSubArrayLen(s, nums) << endl;
    return 0;
}
