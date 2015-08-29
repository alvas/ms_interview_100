#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int ret = 1;
        int M = dungeon.size(), N = 0;

        if (M == 0)
        {
            return ret;
        }

        N = dungeon[0].size();
        vector<vector<int> > dp(M, vector<int>(N, 0));

        for (int i = 1; i < N; ++i)
        {
            dungeon[0][i] += dungeon[0][i - 1];

            if (dungeon[0][i] < 0)
            {
                dp[0][i] = dungeon[0][i];
            }
            else
            {
                dp[0][i] = dp[0][i - 1];
            }
        }

        for (int i = 1; i < M; ++i)
        {
            dungeon[i][0] += dungeon[i- 1][0];

            if (dungeon[i][0] < 0)
            {
                dp[i][0] = dungeon[i][0];
            }
            else
            {
                dp[i][0] = dp[i - 1][0];
            }
        }


        for (int i = 1; i < M; ++i)
        {
            for (int j = 1; j < N; ++j)
            {
                int a = dungeon[i - 1][j] + dungeon[i][j];
                int b = dungeon[i][j- 1] + dungeon[i][j];

                dungeon[i][j] = max(dungeon[i - 1][j] + dungeon[i][j], dungeon[i][j- 1] + dungeon[i][j]);

                if (dungeon[i][j] < 0)
                {
                    dp[i][j] = -dungeon[i][j];
                }
                else
                {
                    if (b < a)
                    {
                    }
                    else
                    {
                    }
                }
            }
        }

        return ret;
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
