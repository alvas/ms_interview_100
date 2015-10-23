#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Need to improve, try non-recursive implementation.
    int totalNQueens(int n) {
        if (n == 0)
        {
            return 0;
        }

        int sum = 0;
        vector<string> r(n, string(n, '.'));
        compute(0, n, r, sum);
        return sum;
    }

    void compute(int r, int n, vector<string> &t, int &sum)
    {
        if (r >= n)
        {
            sum++;
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (check(t, r, i))
            {
                t[r][i] = 'Q';
                compute(r + 1, n, t, sum);
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
    std::cout << sln.totalNQueens(n) << endl;
    return 0;
}
