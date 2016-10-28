#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int row = grid.size();

        if (row == 0) {
            return 0;
        }

        int col = grid[0].size(), res = 0;
        vector<int> ii, jj;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    ii.push_back(i);
                    jj.push_back(j);
                }
            }
        }

        sort(jj.begin(), jj.end());

        int m = ii.size(), idx1 = ii[m / 2], idx2 = jj[m / 2];

        for (int i : ii) {
            res += abs(i - idx1);
        }

        for (int j : jj) {
            res += abs(j - idx2);
        }

        return res;
    }

    int minTotalDistance1(vector<vector<int>>& grid) {
        int row = grid.size();

        if (row == 0) {
            return 0;
        }

        int col = grid[0].size(), res = 0;
        vector<int> rowc(row, 0), colc(col, 0);
        vector<pair<int, int>> v;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    rowc[i]++;
                    colc[j]++;
                    v.push_back(make_pair(i,j));
                }
            }
        }

        // finding a point split them evenly, median point in one dimension
        for (int i = 1; i < row; ++i) {
            rowc[i] += rowc[i - 1];
        }

        // using upper_bound, NOT lower_bound
        int midR = upper_bound(rowc.begin(), rowc.end(), rowc.back() / 2) - rowc.begin();

        for (int i = 1; i < col; ++i) {
            colc[i] += colc[i - 1];
        }

        int midC = upper_bound(colc.begin(), colc.end(), colc.back() / 2) - colc.begin();

        for (auto a: v) {
            res += abs(a.first - midR) + abs(a.second - midC);
        }

        return res;
    }

    int minTotalDistance_slow(vector<vector<int>>& grid) {
        int row = grid.size();

        if (row == 0) {
            return 0;
        }

        // res initial value couldn't be 0, otherwise it would be 0.
        int col = grid[0].size(), res = INT_MAX;
        vector<pair<int, int>> v;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    v.push_back(make_pair(i,j));
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int tmp = 0;

                for (auto v1: v) {
                    tmp += abs(v1.first - i) + abs(v1.second - j);
                }

                res = min(res, tmp);
            }
        }

        return res;
    }
};

int main() {
    Solution sln;
    vector<vector<int>> grid = {
        {1, 0, 0, 0, 1},
        //{0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0}
    };

    cout << sln.minTotalDistance(grid) << endl;
    return 0;
}
