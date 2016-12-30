#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();

        if (row == 0) {
            return 0;
        }

        int col = grid[0].size();

        if (col == 0) {
            return 0;
        }

        int res = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0) {
                    res += grid[i][j];
                }
                else if (!grid[i - 1][j]) {
                    res += grid[i][j];
                }

                if (j == 0) {
                    res += grid[i][j];
                }
                else if (!grid[i][j - 1]) {
                    res += grid[i][j];
                }

                if (i == row - 1) {
                    res += grid[i][j];
                }
                else if (!grid[i + 1][j]) {
                    res += grid[i][j];
                }

                if (j == col - 1) {
                    res += grid[i][j];
                }
                else if (!grid[i][j + 1]) {
                    res += grid[i][j];
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sln;
    vector<vector<int>> grid {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };
    cout << sln.islandPerimeter(grid) << endl;
    return 0;
}
