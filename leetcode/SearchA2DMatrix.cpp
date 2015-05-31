#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int r = matrix.size();

        if (r == 0)
        {
            return false;
        }

        int c = matrix[0].size();

        if (c == 0)
        {
            return false;
        }

        int lR = 0, rR = r;

        while (lR < rR)
        {
            int mR = (lR + rR) / 2;

            // Check the two ends.
            if (matrix[mR][0] == target || matrix[mR][c - 1] == target)
            {
                return true;
            }
            // Be careful about the situation that target fall in the row mR.
            else if (matrix[mR][0] < target && target < matrix[mR][c - 1])
            {
                lR = mR;
                break;
            }
            // target is not in row mR
            else if (matrix[mR][c - 1] < target)
            {
                lR = mR + 1;
            }
            else
            {
                rR = mR;
            }
        }

        // Be very careful that lR would get out of range.
        if (lR >= r)
        {
            return false;
        }

        int lC = 0, rC = c;

        while (lC < rC)
        {
            int mC = (lC + rC) / 2;

            if (matrix[lR][mC] == target)
            {
                return true;
            }
            else if (matrix[lR][mC] < target)
            {
                lC = mC + 1;
            }
            else
            {
                rC = mC;
            }
        }

        return false;
    }
};

int main()
{
    Solution sln;
    int m = 0, n = 0, target = 0;
    cout << "Please enter m: ";
    cin >> m;
    cout << "Please enter n: ";
    cin >> n;
    cout << "Please enter target: ";
    cin >> target;
    vector<vector<int> > matrix;

    vector<int> tmp;
    //initializeRandomVector(tmp, m * n);
    //sort(tmp.begin(), tmp.end());

    //for (int i = 0; i < m; ++i)
    //{
        //vector<int>::iterator start = tmp.begin();
        //int offset = i * n;
        //vector<int> row(start + offset, start + offset + n);
        //matrix.push_back(row);
    //}

    tmp.push_back(1);
    matrix.push_back(tmp);
    
    //initialize2DRandomVector(matrix, n, m);

    print2DVector<int>(matrix);
    cout << sln.searchMatrix(matrix, target) << endl;

    return 0;
}
