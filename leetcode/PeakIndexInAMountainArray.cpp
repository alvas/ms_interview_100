/*
 * PeakIndexInAMountainArray.cpp
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
    int peakIndexInMountainArray(vector<int>& A) {
        int b = 0, e = A.size(), m = (b + e) / 2;
        findPeak(A, b, m, e);
        return m;
    }

    void findPeak(const vector<int> &A, int &b, int &m, int &e) {
        if (A[m - 1] < A[m] && A[m] > A[m + 1]) {
            return;
        }
        else if (A[m - 1] < A[m] && A[m] < A[m + 1]) {
            b = m;
            m = (b + e) / 2;
            findPeak(A, b, m, e);
        }
        else {
            e = m;
            m = (b + e) / 2;
            findPeak(A, b, m, e);
        }
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
        vector<int> A = {0,1,0};
        int res = sln.peakIndexInMountainArray(A);
        CHECK_EQUAL(res,1);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        vector<int> A = {0,2,1,0};
        int res = sln.peakIndexInMountainArray(A);
        CHECK_EQUAL(res,1);
    }
}

