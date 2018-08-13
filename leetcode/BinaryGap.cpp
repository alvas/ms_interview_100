/*
 * BinaryGap.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>

#include "UnitTest.h"

using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        int gap = -1, maxG = 0;

        while (N) {
            if (N % 2 == 1) {
                gap++;
                maxG = max(maxG, gap);
                gap = 0;
            }
            else if (gap != -1) {
                gap++;
            }

            N = N >> 1;
        }

        return maxG;
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
        int N = 22;
        int res = sln.binaryGap(N);
        CHECK_EQUAL(2,res);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        int N = 5;
        int res = sln.binaryGap(N);
        CHECK_EQUAL(2,res);
    }

    TEST_FIXTURE(MyFixture, CASE3)
    {
        int N = 6;
        int res = sln.binaryGap(N);
        CHECK_EQUAL(1,res);
    }

    TEST_FIXTURE(MyFixture, CASE4)
    {
        int N = 0;
        int res = sln.binaryGap(N);
        CHECK_EQUAL(0,res);
    }
}

