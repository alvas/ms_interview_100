#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > v;
        int sz = candidates.size();

        if (sz == 0 || target <= 0)
        {
            return v;
        }

        sort(candidates.begin(), candidates.end());

        vector<int> a;
        compute(0, candidates, target, a, v);
        return v;
    }

    void compute(int b, vector<int> &candidates, int target, vector<int> &a, vector<vector<int> > &v)
    {
        if (target < 0)
        {
            return;
        }
        else if (target == 0)
        {
            v.push_back(a);
            return;
        }

        int sz = candidates.size();

        for (int i = b; i < sz; )
        {
            int tmp = candidates[i];
            a.push_back(tmp);
            compute(i + 1, candidates, target - tmp, a, v);
            a.pop_back();

            while (++i < sz && tmp == candidates[i])
            {
                ;
            }
        }
    }
};

int main()
{
    Solution sln;
    int target = 0;
    cout << "Please enter target: ";
    cin >> target;
    int a[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> candidates(a, a + SIZE(a));
    //vector<int> candidates;
    //initializeRandomVector(candidates, 10);
    vector<vector<int> > v = sln.combinationSum2(candidates, target);
    print2DVector<int>(v);
    return 0;
}
