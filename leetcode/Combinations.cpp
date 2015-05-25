#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > r;

        if (n == 0 || k == 0)
        {
            return r;
        }

        vector<int> v;
        compute(n, 1, k, v, r);
        return r;
    }

    void compute(int n, int s, int k, vector<int> &v, vector<vector<int> > &r)
    {
        if (s > n)
        {
            if (k == 0)
            {
                r.push_back(v);
            }

            return;
        }

        compute(n, s + 1, k, v, r);
        v.push_back(s);
        compute(n, s + 1, k - 1, v, r);
        v.pop_back();
    }
};

int main()
{
    Solution sln;
    int n = 0, k = 0;
    cout << "Please enter n: ";
    cin >> n;
    cout << "Please enter k: ";
    cin >> k;
    vector<vector<int> > v = sln.combine(n, k);
    print2DVector<int>(v);
    return 0;
}
