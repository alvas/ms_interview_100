#include <cmath>
#include <iostream>
#include <set>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
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
            if (i > s && nums[i] == nums[i - 1])
            {
                continue;
            }

            tmp.push_back(nums[i]);
            res.push_back(tmp);

            // IMPORTANT!! start from i + 1, not s + 1
            findSubsets(nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }

    // Need to improve it without using a set.
    vector<vector<int> > subsetsWithDup1(vector<int>& nums) {
        vector<vector<int> > v;
        vector<int> a;
        v.push_back(a);
        int size = nums.size();
        int count = pow(2, size);
        sort(nums.begin(), nums.end());
        set<vector<int> > s;

        for (int i = 1; i < count; ++i)
        {
            int c = i;
            a.clear();
            int index = 0;

            while (c)
            {
                if (c & 1)
                {
                    a.push_back(nums[index]);
                }

                c >>= 1;
                index++;
            }

            if (s.find(a) == s.end())
            {
                v.push_back(a);
                s.insert(a);
            }
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
    initializeRandomVector(nums, n);
    printVector<int>(nums);
    vector<vector<int> > v = sln.subsetsWithDup(nums);
    print2DVector<int>(v);
    return 0;
}
