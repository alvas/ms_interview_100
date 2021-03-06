#include <iostream>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> v;

        int r = matrix.size(), c = 0;

        if (r <= 0)
        {
            return v;
        }
        else
        {
            c = matrix[0].size();
        }

        //int left = 0, right = c - 1, top = 0, bottom = r - 1;

        int row = 0, col = -1;

        while (true)
        {
            for (int i = 0; i < c; ++i)
            {
                v.push_back(matrix[row][++col]);
            }

            if (--r == 0)
            {
                break;
            }

            for (int i = 0; i < r; ++i)
            {
                v.push_back(matrix[++row][col]);
            }

            if (--c == 0)
            {
                break;
            }

            for (int i = 0; i < c; ++i)
            {
                v.push_back(matrix[row][--col]);
            }

            if (--r == 0)
            {
                break;
            }

            for (int i = 0; i < r; ++i)
            {
                v.push_back(matrix[--row][col]);
            }

            if (--c == 0)
            {
                break;
            }
        }

        //// Be careful about the condition.
        //while (left <= right && top <= bottom)
        //{
            //for (int i = left; i <= right; ++i)
            //{
                //v.push_back(matrix[top][i]);
            //}

            //top++;

            //// Be careful about the conditon.
            //if (top > bottom)
            //{
                //return v;
            //}

            //for (int i = top; i <= bottom; ++i)
            //{
                //v.push_back(matrix[i][right]);
            //}

            //right--;
            
            //if (left > right)
            //{
                //return v;
            //}

            //for (int i = right; i >= left; --i)
            //{
                //v.push_back(matrix[bottom][i]);
            //}

            //bottom--;

            //if (top > bottom)
            //{
                //return v;
            //}

            //for (int i = bottom; i >= top; --i)
            //{
                //v.push_back(matrix[i][left]);
            //}

            //left++;

            //if (left > right)
            //{
                //return v;
            //}
        //}

        return v;
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
    initialize2DVector(matrix, m, n);
    print2DVector<int>(matrix);
    std::cout << endl;
    vector<int> r = sln.spiralOrder(matrix);
    printVector<int>(r);
    return 0;
}
