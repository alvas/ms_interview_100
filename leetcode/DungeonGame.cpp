#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int ret = 1;
        int m = dungeon.size(), n = 0;

        if (m == 0)
        {
            return ret;
        }

        n = dungeon[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));

        dp[m - 1][n - 1] = max(1 , 1 - dungeon[m - 1][n - 1]);

        for (int i = m - 2; i >= 0; --i)
        {
            dp[i][n - 1] = max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }

        for (int j = n - 2; j >= 0; --j)
        {
            dp[m - 1][j] = max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        }

        for (int i = m - 2; i >= 0; --i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};

int main()
{
    Solution sln;
    const int M = 3, N = 3;
    int a[M][N] = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    vector<vector<int> > dungeon;

    for (int i = 0; i < M; ++i)
    {
        vector<int> b(a[i], a[i] + N);
        dungeon.push_back(b);
    }

    cout << sln.calculateMinimumHP(dungeon) << endl;
    return 0;
}
