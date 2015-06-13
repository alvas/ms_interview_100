#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    }
};

int main()
{
    Solution sln;
    int target = 0;
    cout << "Please enter target: ";
    cin >> target;
    int a[] = {};
    vector<int> candidates(a, a + SIZE(a));
    vector<vector<int> > v = sln.combinationSum2(candidates, target);
    return 0;
}
