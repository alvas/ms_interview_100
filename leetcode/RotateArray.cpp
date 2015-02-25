#include <algorithm>
#include <iostream>

#include "../RandomData.h"

using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {

        if (n == 0 || k == 0)
        {
            return;
        }

        k = k % n;

        std::reverse(nums, nums + n - k);
        std::reverse(nums + n - k, nums + n);
        std::reverse(nums, nums + n);

        return;
    }
};

int main()
{
    Solution sln;
    int array[7] = {1,2,3,4,5,6,7};
    sln.rotate(array, 7, 3);
    printArray(array, 0, 7 - 1);
    return 0;
}

