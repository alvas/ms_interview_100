#include <cmath>
#include <iostream>
#include <set>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    // Need to improve it without using a set.
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
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
    cout << "Please enter n: ";
    cin >> n;
    vector<int> nums;
    initializeRandomVector(nums, n);
    printVector<int>(nums);
    vector<vector<int> > v = sln.subsetsWithDup(nums);
    print2DVector<int>(v);
    return 0;
}
