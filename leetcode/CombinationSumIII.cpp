#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > v;

        // Be careful about k * 9 < n.
        if (k <= 0 || k > n || k * 9 < n)
        {
            return v;
        }

        vector<int> a;
        compute(1, k, n, a, v);

        return v;
    }

    void compute(int b, int k, int n, vector<int> &a, vector<vector<int> > &v)
    {
        if (k < 0 || (k == 0 && n != 0) || (k > 0 && n <= 0))
        {
            return;
        }
        else if (k == 0 && n == 0)
        {
            v.push_back(a);
            return;
        }

        for (int i = b; i <= 9; ++i)
        {
            a.push_back(i);
            // Be careul about i + 1, because it doesn't allow duplicated number and numbers must be in ascending order.
            compute(i + 1, k - 1, n - i, a, v);
            a.pop_back();
        }
    }
};

int main()
{
    Solution sln;
    int k = 0, n = 0;
    cout << "Please enter k: ";
    cin >> k;
    cout << "Please enter n: ";
    cin >> n;
    vector<vector<int> > v = sln.combinationSum3(k, n);
    print2DVector<int>(v);
    return 0;
}
