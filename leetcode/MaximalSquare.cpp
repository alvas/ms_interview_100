#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n));

        // The first column and row need to use the original value.
        for (int i = 0; i < n; ++i)
        {
            f[0][i] = matrix[0][i];
        }

        for (int i = 0; i < m; ++i)
        {
            f[i][0] = matrix[i][0];
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    f[i][j] = 0;
                }
                else
                {
                    f[i][j] = 1 + min(f[i - 1][j], min(f[i - 1][j - 1], f[i][j - 1]));
                }
            }
        }

        int res = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res = max(res, f[i][j]);
            }
        }

        return res * res;
    }

    // Need to improve.
    int maximalSquare1(vector<vector<char> >& matrix) {
        int maxV = 0;
        int row = matrix.size(), col = 0;

        if (row == 0)
        {
            return maxV;
        }
        else
        {
            col = matrix[0].size();
        }

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (matrix[i][j] == '0')
                {
                    continue;
                }

                int len = min(row - i, col - j);

                // Be careful about the index.
                for (int k = 1; k <= len; ++k)
                {
                    bool allOne = true;

                    for (int m = i; m < i + k; ++m)
                    {
                        for (int n = j; n < j + k; ++n)
                        {
                            if (matrix[m][n] == '0')
                            {
                                allOne = false;
                                break;
                            }
                        }
                    }

                    if (allOne)
                    {
                        // Be careful about the k * k value.
                        maxV = max(k * k, maxV);
                    }
                    else
                    {
                        // pruning.
                        break;
                    }
                }
            }
        }

        return maxV;
    }
};

int main()
{
    Solution sln;
    const int ROW = 1, COL = 1;

    int a[ROW][COL] = {{'1'}};

    //int a[ROW][COL] = 
    //{
        //{'1', '0', '0', '0', '0', '0'},
        //{'1', '1', '0', '1', '1', '0'},
        //{'0', '1', '0', '1', '1', '0'},
        //{'1', '0', '1', '0', '0', '0'},
        //{'0', '1', '1', '0', '1', '0'},
        //{'1', '1', '0', '0', '0', '0'},
    //};

    vector<vector<char> > matrix;

    for (int i = 0; i < ROW; ++i)
    {
        vector<char> b(a[i], a[i] + COL);
        matrix.push_back(b);
    }

    std::cout << sln.maximalSquare(matrix) << endl;
    return 0;
}
