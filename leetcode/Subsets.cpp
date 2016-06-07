#include <cmath>
#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        std::sort(nums.begin(), nums.end());
        findSubsets(nums, 0, tmp, res);
        return res;
    }

    void findSubsets(vector<int> &nums, int s, vector<int> &tmp, vector<vector<int>> &res)
    {
        int m = nums.size();

        for (int i = s; i < m; ++i)
        {
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            // IMPORTANT!! start from i + 1, not s + 1
            findSubsets(nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }

    vector<vector<int> > subsets1(vector<int>& nums) {
        vector<vector<int> > v;

        vector<int> a;
        v.push_back(a);
        int size = nums.size();
        long count = pow(2, size);
        sort(nums.begin(), nums.end());

        for (long i = 1; i < count; ++i)
        {
            a.clear();
            // Remember to use a temp variable, otherwise, it would modify "i".
            long c = i;
            int bit = 0;

            while (c != 0)
            {
                if (c & 1)
                {
                    a.push_back(nums[bit]);
                }

                c >>= 1;
                bit++;
            }

            v.push_back(a);
        }

        return v;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    vector<int> nums;
    initializeIndexVector(nums, n);
    printVector<int>(nums);
    vector<vector<int> > v = sln.subsets(nums);
    print2DVector<int>(v);
    return 0;
}
