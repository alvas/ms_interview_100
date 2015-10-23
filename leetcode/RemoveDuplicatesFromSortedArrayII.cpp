#include <iostream>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
        {
            return size;
        }

        int prev = 0, next = 1, count = 1;

        while (next < size)
        {
            if (nums[prev] == nums[next])
            {
                if (count < 2)
                {
                    prev++;
                    nums[prev] = nums[next];
                    count++;
                    next++;
                }
                else
                {
                    next++;
                }
            }
            else
            {
                prev++;
                nums[prev] = nums[next];
                next++;
                count = 1;
            }
        }

        return prev + 1;
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 9;
    //int a[LOCAL_LENGTH] = {1, 1, 1, 2, 2, 3};
    //int a[LOCAL_LENGTH] = {1};
    //int a[LOCAL_LENGTH] = {1, 1};
    //int a[LOCAL_LENGTH] = {1, 1, 1};
    //int a[LOCAL_LENGTH] = {1, 1, 2};
    //int a[LOCAL_LENGTH] = {1, 2, 2};
    //int a[LOCAL_LENGTH] = {1, 1, 2, 2};
    //int a[LOCAL_LENGTH] = {1, 1, 1, 2, 2};
    //int a[LOCAL_LENGTH] = {1, 1, 1, 1, 2};
    //int a[LOCAL_LENGTH] = {1, 1, 2, 2, 2};
    //int a[LOCAL_LENGTH] = {1, 1, 2, 2, 3, 3};
    //int a[LOCAL_LENGTH] = {1, 2, 3, 4, 5, 6};
    //int a[LOCAL_LENGTH] = {1, 1, 1, 2, 3, 3};
    //int a[LOCAL_LENGTH] = {1, 1, 1, 2, 3, 3, 3};
    //int a[LOCAL_LENGTH] = {1, 2, 2, 2, 2, 2, 3};
    int a[LOCAL_LENGTH] = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    vector<int> nums(a, a + LOCAL_LENGTH);
    std::cout << sln.removeDuplicates(nums) << endl;
    printVector<int>(nums);
    return 0;
}
