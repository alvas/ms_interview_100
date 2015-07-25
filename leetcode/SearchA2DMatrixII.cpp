#include <iostream>
#include <vector>

#include "RandomData.h"

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();

        if (row == 0)
        {
            return false;
        }

        int col = matrix[0].size();

        if (col == 0)
        {
            return false;
        }

        int l = 0, r = col, t = 0, b = row;
        return search(matrix, l, r, t, b, target);
    }

    bool search(vector<vector<int> > &matrix, int l, int r, int t, int b, int target)
    {
        if (l >= r || t >= b)
        {
            return false;
        }
        else if (target < matrix[t][l] || matrix[b - 1][r - 1] < target)
        {
            return false;
        }
        else if (target == matrix[t][l] || matrix[b - 1][r - 1] == target)
        {
            return true;
        }

        int cm = (l + r) / 2, rm = (t + b) / 2;

        // Be very very careful about the boundary.
        // Think carefully what exactly they are, please.
        if (matrix[rm][cm] == target)
        {
            return true;
        }
        else if (matrix[rm][cm] < target)
        {
            return search(matrix, cm + 1, r, t, b, target) || 
                   search(matrix, l, cm + 1, rm + 1, b, target);
        }
        else
        {
            return search(matrix, l, cm, t, b, target) || 
                   search(matrix, cm, r, t, rm, target);
        }
    }

    bool searchMatrix_navie(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();

        if (row == 0)
        {
            return false;
        }

        int col = matrix[0].size();

        if (col == 0)
        {
            return false;
        }

        if (target < matrix[0][0] || matrix[row - 1][col - 1] < target)
        {
            return false;
        }
        else if (target == matrix[0][0] || matrix[row - 1][col - 1] == target)
        {
            return true;
        }

        for (int i = 0; i < row; ++i)
        {
            vector<int>::iterator itr = std::find(matrix[i].begin(), matrix[i].end(), target);

            if (itr != matrix[i].end())
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution sln;
    cout << "Please enter target: ";
    int target = 0;
    cin >> target;
    vector<vector<int> > matrix;

    //int m = 0, n = 0;
    //cout << "Please enter m: ";
    //cin >> m;
    //cout << "Please enter n: ";
    //cin >> n;
    //initialize2DRandomVector(matrix, n, m);

    //const int ROW = 1, COL = 1;
    //int a[ROW][COL] = {{3}};

    //const int ROW = 1, COL = 5;
    //int a[ROW][COL] = {{1, 2, 3, 4, 5}};

    //const int ROW = 5, COL = 5;
    //int a[ROW][COL] = 
    //{{1, 4, 7, 11, 15}, 
     //{2, 5, 8, 12, 19}, 
     //{3, 6, 9, 16, 22}, 
     //{10, 13, 14, 17, 24}, 
     //{18, 21, 23, 26, 30}};

    //int a[ROW][COL] = 
    //{{1,2,3,4,5},
     //{6,7,8,9,10},
     //{11,12,13,14,15},
     //{16,17,18,19,20},
     //{21,22,23,24,25}};
     
    const int ROW = 7, COL = 6;
    int a[ROW][COL] = 
    {{3,3,8,13,13,18},
     {4,5,11,13,18,20},
     {9,9,14,15,23,23},
     {13,18,22,22,25,27},
     {18,22,23,28,30,33},
     {21,25,28,30,35,35},
     {24,25,33,36,37,40}};

    for (int i = 0; i < ROW; ++i)
    {
        vector<int> r(a[i], a[i] + COL);
        matrix.push_back(r);
    }

    print2DVector<int>(matrix);
    cout << sln.searchMatrix_navie(matrix, target) << endl;
    cout << sln.searchMatrix(matrix, target) << endl;
    return 0;
}
