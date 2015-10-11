#include <iostream>
#include <stack>
#include <vector>

#include "NormalData.h"

using namespace std;

class Solution {
public:
    // May need to improve.
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();
        // Initial value INT_MAX is important. If initialize it to 0, then it will always get the wrong answer 0.
        int min = INT_MAX;

        for (int i = 1; i < row; ++i)
        {
            triangle[i][0] += triangle[i - 1][0];
        }

        for (int i = 1; i < row; ++i)
        {
            triangle[i][i] += triangle[i - 1][i - 1];
        }

        for (int i = 2; i < row; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                int tmp = triangle[i - 1][j - 1] < triangle[i - 1][j] ? triangle[i - 1][j - 1]: triangle[i - 1][j];

                triangle[i][j] += tmp;

                // Don't check the min value here, because it doesn't loop through all value in the last row.
            }
        }

        for (int i = 0; i < row; ++i)
        {
            min = triangle[row - 1][i] < min ? triangle[row - 1][i] : min;
        }

        return min;
    }

    int minimumTotal_slow(vector<vector<int> > &triangle) {
        int row = triangle.size();
        stack<int> s;

        int min = INT_MAX, sum = 0;
        int r = 0, c = 0;

        s.push(c);
        sum += triangle[r++][c];

        while (!s.empty())
        {
            while (r < row)
            {
                s.push(c);
                sum += triangle[r++][c];
            }

            r--;

            if (sum < min)
            {
                min = sum;
            }

            int top = s.top();
            sum -= triangle[r--][top];
            s.pop();

            while (!s.empty() && top != s.top())
            {
                top = s.top();
                sum -= triangle[r--][top];
                s.pop();
            }

            r++;
            c = top + 1;
        }

        return min;
    }

    int minimumTotal_recursive(vector<vector<int> > &triangle) {
        int minVal = INT_MAX, val = 0, level = 0, index = 0;
        int row = triangle.size();
        compute(triangle, row, level, index, val, minVal);
        return minVal;
    }

    void compute(const vector<vector<int> > &triangle, int row, int level, int index, int val, int &min)
    {
        if (row <= level)
        {
            if (val < min)
            {
                min = val;
            }

            return;
        }

        int col = triangle[level].size();

        compute(triangle, row, level + 1, index, val + triangle[level][index], min);
        
        if (index + 1 < col)
        {
            compute(triangle, row, level + 1, index + 1, val + triangle[level][index + 1], min);
        }
    }
};

int main()
{
    Solution sln;
    vector<vector<int> > triangle;
    vector<int> a1 = {2};
    vector<int> a2 = {3, 4};
    vector<int> a3 = {6, 5, 7};
    vector<int> a4 = {4, 1, 8, 3};
    vector<int> a(a1, a1 + SIZE(a1));
    triangle.push_back(a);
    a.assign(a2, a2 + SIZE(a2));
    triangle.push_back(a);
    a.assign(a3, a3 + SIZE(a3));
    triangle.push_back(a);
    a.assign(a4, a4 + SIZE(a4));
    triangle.push_back(a);
    print2DVector<int>(triangle);
    cout << sln.minimumTotal_recursive(triangle) << endl;
    cout << sln.minimumTotal_slow(triangle) << endl;
    cout << sln.minimumTotal(triangle) << endl;
    return 0;
}
