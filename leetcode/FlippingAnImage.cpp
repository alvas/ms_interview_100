/*
 * FlippingAnImage.cpp
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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row = A.size(), col = A[0].size(), col2 = (col + 1)/ 2;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col2; ++j) {
                int tmp = A[i][j];
                A[i][j] = !A[i][col - 1 - j];
                A[i][col - 1 - j] = !tmp;
            }
        }

        return A;
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
        vector<vector<int>> A = {{1,1,0},{1,0,1},{0,0,0}};
        vector<vector<int>> B = {{1,0,0},{0,1,0},{1,1,1}};
        vector<vector<int>> res = sln.flipAndInvertImage(A);
        CHECK_EQUAL(res == B, true);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        vector<vector<int>> A ={{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
        vector<vector<int>> B = {{1,1,0,0},{0,1,1,0},{0,0,0,1},{1,0,1,0}};
        vector<vector<int>> res = sln.flipAndInvertImage(A);
        CHECK_EQUAL(res == B, true);
    }
}

