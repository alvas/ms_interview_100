#include <iostream> 
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Need to improve
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > v;
        vector<int> tmp;
        // sort the array, so it is in non-descending order.
        sort(candidates.begin(), candidates.end()); 
        calculate(v, 0, tmp, candidates, target);
        return v;
    }

    void calculate(vector<vector<int> > &v, int start, vector<int> tmp, vector<int> &candidates, int target)
    {
        if (target < 0)
        {
            return;
        }
        else if (target == 0)
        {
            v.push_back(tmp);
        }
        else
        {
            int size = candidates.size();

            // start index is importatnt for non-descending order
            for (int i = start; i < size; ++i)
            {
                tmp.push_back(candidates[i]);
                calculate(v, i, tmp, candidates, target - candidates[i]);
                // remember to pop out the element.
                tmp.pop_back();
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
    int a[] = {2, 3, 6, 7};
    vector<int> candidates(a, a + SIZE(a));
    vector<vector<int> > v = sln.combinationSum(candidates, target);
    print2DVector<int>(v);
    return 0;
}
