/*
 * ProjectionAreaOf3DShapes.cpp
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
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0;
        int r = grid.size(), c = grid[0].size();

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j])
                    res++;
            }
        }

        for (int i = 0; i < r; ++i) {
            int maxV = *max_element(grid[i].begin(), grid[i].end());
            res += maxV;
        }

        for (int j = 0; j < c; ++j) {
            int maxV = 0;

            for (int i = 0; i < r; ++i) {
                maxV = max(maxV, grid[i][j]);
            }

            res += maxV;
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
        vector<vector<int>> grid = {{2}};
        int res = sln.projectionArea(grid);
        CHECK_EQUAL(res, 5);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        vector<vector<int>> grid = {{1,2},{3,4}};
        int res = sln.projectionArea(grid);
        CHECK_EQUAL(res, 17);
    }

    TEST_FIXTURE(MyFixture, CASE3)
    {
        vector<vector<int>> grid = {{1,0},{0,2}};
        int res = sln.projectionArea(grid);
        CHECK_EQUAL(res, 8);
    }

    TEST_FIXTURE(MyFixture, CASE4)
    {
        vector<vector<int>> grid = {{1,1,1},{1,0,1},{1,1,1}};
        int res = sln.projectionArea(grid);
        CHECK_EQUAL(res, 14);
    }

    TEST_FIXTURE(MyFixture, CASE5)
    {
        vector<vector<int>> grid = {{2,2,2},{2,1,2},{2,2,2}};
        int res = sln.projectionArea(grid);
        CHECK_EQUAL(res, 21);
    }
}

