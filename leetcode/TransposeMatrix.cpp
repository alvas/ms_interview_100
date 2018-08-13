/*
 * TransposeMatrix.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>

#include "UnitTest.h"
#include "NormalData.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int r = A.size(), c = A[0].size();
        vector<vector<int>> res(c, vector<int>(r, 0));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                res[j][i] = A[i][j];
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
        vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
        vector<vector<int>> res = sln.transpose(A);
        vector<vector<int>> B = {{1,4,7},{2,5,8},{3,6,9}};
        print2DVector<int>(res);
        CHECK_EQUAL(true, res == B);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        vector<vector<int>> A = {{1,2,3},{4,5,6}};
        vector<vector<int>> res = sln.transpose(A);
        vector<vector<int>> B = {{1,4},{2,5},{3,6}};
        print2DVector<int>(res);
        CHECK_EQUAL(true, res == B);
    }
}

