#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Can be improved!
    int removeDuplicates(vector<int>& nums) {
        size_t m = nums.size(); 

        // Be careful about zero size. We should not return ++i for it.
        if (!m)
        {
            return 0;
        }

        int i = 0;

        for (int j = 1; j < m; ++j)
        {
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
        }

        nums.resize(++i);
        return i;
    }
};

int main()
{
    Solution sln;
    vector<int> A = {1, 2, 2, 2, 3, 4, 5, 6};
    printVector<int>(A);
    std::cout << sln.removeDuplicates(A) << endl;
    printVector<int>(A);
    return 0;
}

