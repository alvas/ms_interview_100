#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinPath(vector< vector<int> > &grid)
    {
        if (grid.size() == 0)
        {
            return 0;
        }

        int x = grid.size();
        int y = grid[0].size();

        for (int i = 1; i < x; ++i)
        {
            grid[i][0] = grid[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < y; ++i)
        {
            grid[0][i] = grid[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < x; ++i)
        {
            for (int j = 1; j < y; ++j)
            {
                int sum1 = grid[i][j] + grid[i - 1][j];
                int sum2 = grid[i][j] + grid[i][j - 1];

                grid[i][j] = sum1 < sum2 ? sum1 : sum2;
            }
        }

        return grid[x - 1][y - 1];
    }
    
    int minPathSum(vector<vector<int> > &grid) {
        int min = findMinPath(grid);
        return min;
    }
};

int main()
{
    Solution sln;
    return 0;
}
