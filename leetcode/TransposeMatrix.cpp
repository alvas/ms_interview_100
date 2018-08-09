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
        vector<vector<int>> res;
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
        print2DVector<int>(res);
        //CHECK_EQUAL(,);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        vector<vector<int>> A = {{1,2,3},{4,5,6}};
        vector<vector<int>> res = sln.transpose(A);
        print2DVector<int>(res);
        //CHECK_EQUAL(,);
    }
}

