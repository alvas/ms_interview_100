#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > r;
        int size = nums.size();

        if (size == 0)
        {
            return r;
        }

        compute(nums, 0, r);
        return r;
    }

    void compute(vector<int> &nums, int start, vector<vector<int> > &r)
    {
        int size = nums.size();

        if (start == size)
        {
            r.push_back(nums);
            return;
        }

        for (int i = start; i < size; ++i)
        {
            swap(nums[start], nums[i]);
            compute(nums, start + 1, r);
            swap(nums[start], nums[i]);
        }
    }
};

int main()
{
    Solution sln;
    int a[] = {1, 2, 3, 4};
    vector<int> nums(a, a + SIZE(a));
    //const int LOCAL_LENGTH = 10;
    //vector<int> nums;
    //initializeIndexVector(nums, LOCAL_LENGTH);
    vector<vector<int> > v = sln.permute(nums);
    print2DVector<int>(v);
    cout << "size: " << v.size() << endl;
    return 0;
}
