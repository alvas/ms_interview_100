#include <iostream>
#include <set>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    // Need to improve it.
    void setZeroes(vector<vector<int> >& matrix) {
        int rows = matrix.size(), columns = 0;

        if (rows == 0)
        {
            return;
        }

        columns = matrix[0].size();

        if (columns == 0)
        {
            return;
        }

        bool zeroRow = false, zeroColumn = false;

        for (int i = 0; i < columns; ++i)
        {
            if (matrix[0][i] == 0)
            {
                zeroRow = true;
                break;
            }
        }

        for (int i = 0; i < rows; ++i)
        {
            if (matrix[i][0] == 0)
            {
                zeroColumn = true;
                break;
            }
        }

        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < columns; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    for (int k = j - 1; k >= 0; --k)
                    {
                        matrix[i][k] = 0;
                    }

                    for (int k = i - 1; k >= 0; --k)
                    {
                        matrix[k][j] = 0;
                    }
                }
            }
        }

        for (int i = 1; i < columns; ++i)
        {
            if (matrix[0][i] == 0)
            {
                for (int j = 1; j < rows; ++j)
                {
                    matrix[j][i] = 0;
                }
            }
        }

        for (int i = 1; i < rows; ++i)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 1; j < columns; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (zeroRow)
        {
            for (int i = 0; i < columns; ++i)
            {
                matrix[0][i] = 0;
            }
        }

        if (zeroColumn)
        {
            for (int i = 0; i < rows; ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }

    void setZeroes_common(vector<vector<int> >& matrix) {
        int rows = matrix.size(), columns = 0;

        if (rows == 0)
        {
            return;
        }

        columns = matrix[0].size();

        if (columns == 0)
        {
            return;
        }

        set<int> rowSet, columnSet;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    rowSet.insert(i);
                    columnSet.insert(j);
                }
            }
        }

        for (set<int>::iterator itr = rowSet.begin(); itr != rowSet.end(); ++itr)
        {
            for (int i = 0; i < columns; ++i)
            {
                matrix[*itr][i] = 0;
            }
        }

        for (set<int>::iterator itr = columnSet.begin(); itr != columnSet.end(); ++itr)
        {
            for (int i = 0; i < columns; ++i)
            {
                matrix[i][*itr] = 0;
            }
        }
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

    vector<vector<int> > matrix;

    for (int i = 0; i < m; ++i)
    {
        vector<int> v;
        initializeRandomVector(v, n);
        matrix.push_back(v);
    }


    for (int i = 0; i < 4; ++i)
    {
        int j = rand() % m;
        int k = rand() % n;
        std::cout << j << ", " << k << endl;

        matrix[j][k] = 0;
    }

    print2DVector<int>(matrix);
    sln.setZeroes(matrix);
    std::cout << endl;
    print2DVector<int>(matrix);
    return 0;
}
