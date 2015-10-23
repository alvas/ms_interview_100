#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    // Because the robot can move either down or right, so this solution is OK.
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int row = obstacleGrid.size(), col = 0;

        if (row == 0)
        {
            return 0;
        }
        else if (row > 0)
        {
            col = obstacleGrid[0].size();
        }

        vector<vector<int> > v(row, vector<int>(col, 0));

        for (int i = 0; i < col; ++i)
        {
            if (obstacleGrid[0][i] == 1)
            {
                break;
            }

            v[0][i] = 1;
        }

        for (int i = 0; i < row; ++i)
        {
            if (obstacleGrid[i][0] == 1)
            {
                break;
            }
            
            v[i][0] = 1;
        }

        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                if (obstacleGrid[i][j] != 1)
                {
                    v[i][j] = v[i - 1][j] + v[i][j - 1];
                }
            }
        }

        return v[row - 1][col - 1];
    }

    int uniquePathsWithObstacles_slow(vector<vector<int> >& obstacleGrid) {
        int paths = 0;
        int row = obstacleGrid.size(), col = 0;

        if (row == 0)
        {
            return 0;
        }
        else if (row > 0)
        {
            col = obstacleGrid[0].size();
        }

        findPath(obstacleGrid, row, col, 0, 0, paths);

        return paths;
    }

    void findPath(vector<vector<int> > &grid, int row, int col, int i, int j, int &paths)
    {
        if (i == row - 1 && j == col - 1)
        {
            paths++;
            return;
        }
        else if (i >= row || j >= col || i < 0 || j < 0)
        {
            return;
        }
        else if (grid[i][j] == 1)
        {
            return;
        }

        grid[i][j] = 1;

        findPath(grid, row, col, i + 1, j, paths);
        findPath(grid, row, col, i, j + 1, paths);
        // If the robot can move to any direction, then we need this.
        //findPath(grid, row, col, i + 1, j, paths);
        //findPath(grid, row, col, i, j + 1, paths);

        grid[i][j] = 0;
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
    vector<vector<int> > grid(m, vector<int>(n, 0));
    srand(unsigned(time(0)));

    int numObstacles = (m * n) * 0.2;

    for (int i = 0; i < numObstacles; ++i)
    {
        int row = rand() % m;
        int col = rand() % n;
        grid[row][col] = 1;
    }

    print2DVector<int>(grid);
    std::cout << endl;
    std::cout << sln.uniquePathsWithObstacles(grid) << endl;
    //std::cout << sln.uniquePathsWithObstacles_slow(grid) << endl;
    return 0;
}
