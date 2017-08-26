#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ans = M;
        int rows = M.size();

        if (rows == 0) {
            return ans;
        }

        int cols = M[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ans[i][j] = smooth(M, i,  j);
            }
        }

        return ans;
    }

    int smooth(const vector<vector<int>> &M, int r, int c) {
        int rows = M.size(), cols = M[0].size();
        int count = 0, sum = 0;

        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                // be careful about counting valid cell
                if (0 <= r + i && r + i < rows && 0 <= c + j && c + j < cols) {
                    count++;

                    // be careful about sum up value of valid cell
                    if (M[r + i][c + j] != 0) {
                        sum += M[r + i][c + j];
                    }
                }
            }
        }

        return count == 0 ? 0 : sum / count;
    }
};

int main()
{
    Solution sln;
    vector<vector<int>> M = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> ans = sln.imageSmoother(M);
    print2DVector<int>(ans);
    return 0;
}
