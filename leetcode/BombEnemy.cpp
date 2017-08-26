#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int row = grid.size(), col = 0, ans = 0;

        if (row == 0 || grid[0].size() == 0) {
            return ans;
        }

        col = grid[0].size();

        vector<vector<int>> count(row, vector<int>(col, 0));

        for (int i = 0; i < row; ++i) {
            int head = 0, tail = 0;

            for (int j = 0; j < col; ++j) {
                count[i][j] = grid[i][j] != '0' ? 0 : (count[i][j] + head);
                count[i][col - j - 1] = grid[i][col - j - 1] != '0' ? 0 : (count[i][col - j - 1] + tail);
                head = grid[i][j] == 'W' ? 0 : (head + (grid[i][j] == 'E' ? 1 : 0));
                tail = grid[i][col - j - 1] == 'W' ? 0 : (tail + (grid[i][col - j - 1] == 'E' ? 1 : 0));
            }
        }

        for (int j = 0; j < col; ++j) {
            int head = 0, tail = 0;

            for (int i = 0; i < row; ++i) {
                count[i][j] = grid[i][j] != '0' ? 0 : (count[i][j] + head);
                count[row - i - 1][j] = grid[row - i - 1][j] != '0' ? 0 : (count[row - i - 1][j] + tail);
                head = grid[i][j] == 'W' ? 0 : (head + grid[i][j] == 'E' ? 1 : 0);
                tail = grid[row - i - 1][j] == 'W' ? 0 : (tail + (grid[row - i - 1][j] == 'E' ? 1 : 0));
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                ans = max(ans, count[i][j]);
            }
        }

        return ans;
    }

    int maxKilledEnemies2(vector<vector<char>>& grid) {
        int ans = 0;
        int rows = grid.size();

        if (rows == 0) {
            return ans;
        }

        int cols = grid[0].size();

        vector<vector<int>> rSum(rows, vector<int>(cols, 0)), cSum(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            int l = 0, r = 0;
            int count = 0;

            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '0') {
                    r++;
                }
                else if (grid[i][j] == 'W') {
                    for (int k = l; k < r; ++k) {
                        if (grid[i][k] == '0') {
                            rSum[i][k] = count;
                        }
                    }

                    l = j + 1;
                    r = j + 1;
                    count = 0;
                }
                else {
                    r++;
                    count++;
                }
            }

            // thre is no W at the end
            for (int k = l; k < r; ++k) {
                if (grid[i][k] == '0') {
                    rSum[i][k] = count;
                }
            }

        }

        for (int i = 0; i < cols; ++i) {
            int t = 0, b = 0;
            int count = 0;

            for (int j = 0; j < rows; ++j) {
                if (grid[j][i] == '0') {
                    b++;
                }
                else if (grid[j][i] == 'W') {
                    for (int k = t; k < b; ++k) {
                        if (grid[k][i] == '0') {
                            cSum[k][i] = count;
                        }
                    }

                    t = j + 1;
                    b = j + 1;
                    count = 0;
                }
                else {
                    b++;
                    count++;
                }
            }

            for (int k = t; k < b; ++k) {
                if (grid[k][i] == '0') {
                    cSum[k][i] = count;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ans = max(ans, rSum[i][j] + cSum[i][j]);
            }
        }

        return ans;
    }

    int maxKilledEnemies1(vector<vector<char>>& grid) {
        int ans = 0;
        int rows = grid.size();

        if (rows == 0) {
            return ans;
        }

        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int count = 0;

                if (grid[i][j] == '0') {
                    count = bomb(grid, i, j);
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }

    int bomb(const vector<vector<char>> &grid, int r, int c) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;

        for (int i = c - 1; i >= 0; --i) {
            if (grid[r][i] == 'E') {
                count++;
            }
            else if (grid[r][i] == 'W') {
                break;
            }
        }

        for (int i = c + 1; i < cols; ++i) {
            if (grid[r][i] == 'E') {
                count++;
            }
            else if (grid[r][i] == 'W') {
                break;
            }
        }

        for (int i = r - 1; i >= 0; --i) {
            if (grid[i][c] == 'E') {
                count++;
            }
            else if (grid[i][c] == 'W') {
                break;
            }
        }

        for (int i = r + 1; i < rows; ++i) {
            if (grid[i][c] == 'E') {
                count++;
            }
            else if (grid[i][c] == 'W') {
                break;
            }
        }

        return count;
    }
};

int main()
{
    Solution sln;
    vector<vector<char>> grid = {{'0', 'E', '0', '0'}, {'E', '0', 'W', 'E'}, {'0', 'E', '0', '0'}};
    //vector<vector<char>> grid = {{'E'}};
    cout << sln.maxKilledEnemies(grid) << endl;
    return 0;
}
