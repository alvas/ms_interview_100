#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int m = nums.size();
        int r = 0, b = m - 1;
        int i = 0;

        while (i <= b)
        {
            if (nums[i] == 0)
            {
                swap(nums[i++], nums[r++]);
            }
            else if (nums[i] == 1)
            {
                i++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[b--]);
            }
        }
    }

    void sortColors1(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
        {
            return;
        }

        int l = 0, r = size - 1;

        while (l < r)
        {
            while (l < r && nums[l] == 0)
            {
                l++;
            }

            if (nums[l] == 1)
            {
                int m = l + 1;

                while (m <= r && nums[m] != 0)
                {
                    m++;
                }

                if (m <= r)
                {
                    int tmp = nums[l];
                    nums[l] = nums[m];
                    nums[m] = tmp;
                }

                l++;
            }
            else if (nums[l] == 2)
            {
                while (l < r && nums[r] == 2)
                {
                    r--;
                }

                if (l < r)
                {
                    int tmp = nums[r];
                    nums[r] = nums[l];
                    nums[l] = tmp;
                }

                r--;
            }
        }
    }

    void sortColors_naive(vector<int>& nums) {
        int size = nums.size();

        if (size == 0)
        {
            return;
        }

        int num0 = 0, num1 = 0, num2 = 0;

        for (int i = 0; i < size; ++i)
        {
            if (nums[i] == 0)
            {
                num0++;
            }
            else if (nums[i] == 1)
            {
                num1++;
            }
            else if (nums[i] == 2)
            {
                num2++;
            }
        }

        int num01 = num0 + num1;

        for (int i = 0; i < size; ++i)
        {
            if (i < num0)
            {
                nums[i] = 0;
            }
            else if (i < num01)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 2;
            }
        }
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 2;
    //int a[LOCAL_LENGTH] = {0, 1};
    int a[LOCAL_LENGTH] = {1, 0};
    //int a[LOCAL_LENGTH] = {0, 1, 2, 0, 0, 2, 1, 2, 1, 1};
    vector<int> nums(a, a + LOCAL_LENGTH);
    printVector<int>(nums);
    sln.sortColors(nums);
    printVector<int>(nums);
    return 0;
}
