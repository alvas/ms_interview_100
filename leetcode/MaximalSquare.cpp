#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    // Need to improve.
    int maximalSquare(vector<vector<char> >& matrix) {
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
