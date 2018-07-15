/*
 * ScoreAfterFlippingMatrix.cpp
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
    int matrixScore(vector<vector<int>>& A) {
        int row = A.size(), col = A[0].size();

        for (int i = 0; i < row; ++i) {
            if (A[i][0] == 0) {
                for_each(A[i].begin(), A[i].end(), [](int &a){ a = !a; });
            }
        }

        int row2 = (row + 1) / 2;

        for (int j = 1; j < col; ++j) {
            int sum = 0;

            for (int i = 0; i < row; ++i) {
                sum += A[i][j];
            }

            if (sum < row2) {
                for (int i = 0; i < row; ++i) {
                    A[i][j] = !A[i][j];
                }
            }
        }

        int res = 0;
        int base = 1 << 0;

        for (int j = col - 1; j >= 0; --j) {
            int sum = 0;

            for (int i = 0; i < row; ++i) {
                sum += A[i][j];
            }

            res += sum * base;
            base <<= 1;
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
        vector<vector<int>> A = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
        int res = sln.matrixScore(A);
        CHECK_EQUAL(res, 39);
    }
}

