#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // Need to improve, try non-recursive implementation.
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > v;

        if (n == 0)
        {
            return v;
        }

        vector<string> t(n, string(n, '.'));
        compute(0, n, t, v);
        return v;
    }

    void compute(int r, int n, vector<string> &t, vector<vector<string> > &v)
    {
        if (r >= n)
        {
            v.push_back(t);
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (check(t, r, i))
            {
                t[r][i] = 'Q';
                compute(r + 1, n, t, v);
                t[r][i] = '.';
            }
        }
    }

    bool check(const vector<string> &r, int i, int j)
    {
        int size = r.size();

        for (int k = 0; k < i; ++k)
        {
            if (r[k][j] == 'Q')
            {
                return false;
            }
        }

        for (int k = i - 1, m = j - 1, n = j + 1; k >= 0; --k, --m, ++n)
        {
            if (m >= 0)
            {
                if (r[k][m] == 'Q')
                {
                    return false;
                }
            }

            if (n < size)
            {
                if (r[k][n] == 'Q')
                {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution sln;
    int n = 0;
    std::cout << "Please enter n: ";
    cin >> n;
    vector<vector<string> > v = sln.solveNQueens(n);
    print2DVector2<string>(v);
    return 0;
}
