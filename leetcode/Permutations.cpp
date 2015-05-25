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
            int tmp = nums[i];
            nums[i] = nums[start];
            nums[start] = tmp;
            compute(nums, start + 1, r);
            tmp = nums[i];
            nums[i] = nums[start];
            nums[start] = tmp;
        }
    }
};

int main()
{
    Solution sln;
    const int LOCAL_LENGTH = 5;
    vector<int> nums;
    initializeIndexVector(nums, LOCAL_LENGTH);
    vector<vector<int> > v = sln.permute(nums);
    print2DVector<int>(v);
    cout << "size: " << v.size() << endl;
    return 0;
}
