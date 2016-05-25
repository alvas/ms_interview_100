#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0)
        {
            return 0;
        }
        //// Be careful about the corner case.
        //else if (m == 1 && n == 1)
        //{
            //return 1;
        //}

        // With a better initial value, we can avoid some special checking and initial setting.
        // Use a one dimention array, the code is even simpler.
        vector<vector<int> > v(n, vector<int>(m, 1));

        //for (int i = 1; i < m; ++i)
        //{
            //v[0][i] = 1;
        //}

        for (int i = 1; i < n; ++i)
        {
            v[i][0] = 1;
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                v[i][j] = v[i - 1][j] + v[i][j - 1];
            }
        }

        return v[n - 1][m - 1];
    }

    int uniquePaths_slow2(int m, int n) {
        return backtrack(0, 0, m, n);
    }

    int backtrack(int r, int c, int m, int n)
    {
        if (r == m - 1 && c == n - 1)
        {
            return 1;
        }

        if (r >= m || c >= n)
        {
            return 0;
        }

        return backtrack(r + 1, c, m, n) + backtrack(r, c + 1, m, n);
    }

    int uniquePaths_slow(int m, int n) {
        if (m == 0 || n == 0)
        {
            return 0;
        }

        int sum = 0;
        // Be careful to start from (1, 1).
        return findPath(1, 1, m, n, sum);
    }

    int findPath(int x, int y, int m, int n, int &sum)
    {
        if (x == m && y == n)
        {
            return ++sum;
        }
        else if (x > m || y > n)
        {
            return sum;
        }

        findPath(x + 1, y, m, n, sum);
        findPath(x, y + 1, m, n, sum);
        return sum;
    }
};

int main()
{
    Solution sln;
    int m = 0, n = 0;
    std::cout << "Please enter m: ";
    cin >> m;
    std::cout << "Please enter n: ";
    cin >> n;
    std::cout << sln.uniquePaths(m, n) << endl;
    return 0;
}
