/*
 * MaxIncreaseToKeepCitySkyline.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <vector>

#include "UnitTest.h"

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> rowM(row), colM(col);

        for (int i = 0; i < row; ++i) {
            rowM[i] = *max_element(grid[i].begin(), grid[i].end());
        }

        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                colM[i] = max(colM[i], grid[j][i]);
            }
        }

        int res = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int minV = min(rowM[i], colM[j]);
                if (grid[i][j] < minV) {
                    res += minV - grid[i][j];
                }
            }
        }

        return res;
    }
};

SUITE(TEST_CASES)
{
    class MyFixture
    {
    public:
        Solution sln;
    };

    TEST_FIXTURE(MyFixture, CASE1)
    {
        vector<vector<int>> grid = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
        int res = sln.maxIncreaseKeepingSkyline(grid);
        CHECK_EQUAL(res, 35);
    }
}

