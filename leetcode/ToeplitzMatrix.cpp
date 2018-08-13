/*
 * ToeplitzMatrix.cpp
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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();

        for (int i = 0; i < c; ++i) {
            int v = matrix[0][i];

            for (int j = 1; j < r && i + j < c; ++j) {
                if (v != matrix[j][i + j]) {
                    return false;
                }
            }
        }

        for (int i = 1; i < r; ++i) {
            int v = matrix[i][0];

            for (int j = 1; j < c && i + j < r; ++j) {
                if (v != matrix[i + j][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isToeplitzMatrix1(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();

        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }

        return true;
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
        vector<vector<int>> matrix = {
            {1,2,3,4},
            {5,1,2,3},
            {9,5,1,2}
        };
        bool ans = sln.isToeplitzMatrix(matrix);
        CHECK_EQUAL(true, ans);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        vector<vector<int>> matrix = {
            {1,2},
            {2,2},
        };
        bool ans = sln.isToeplitzMatrix(matrix);
        CHECK_EQUAL(false, ans);
    }
}

