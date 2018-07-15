/*
 * NumberOfLinesToWriteString.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <string>
#include <vector>

#include "NormalData.h"
#include "UnitTest.h"

using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res(2, 0);
        int count = 0, num = 0;

        for (auto s: S) {
            count += widths[s - 'a'];

            if (count <= 100) {
                num++;
            }
            else {
                if (num > 1) {
                    res[0]++;
                }

                num = 1;
                count = widths[s - 'a'];
            }

        }

        res[0]++;
        res[1] = count;
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
        vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
        string S("abcdefghijklmnopqrstuvwxyz");
        vector<int> output = {3, 60};
        vector<int> res = sln.numberOfLines(widths, S);
        printVector<int>(res);
        CHECK_EQUAL(output == res, true);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        vector<int> widths = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
        string S("bbbcccdddaaa");
        vector<int> output = {2, 4};
        vector<int> res = sln.numberOfLines(widths, S);
        printVector<int>(res);
        CHECK_EQUAL(output == res, true);
    }

    TEST_FIXTURE(MyFixture, CASE3)
    {
        vector<int> widths = {10,10,10,10,5,10,10,10,10,10,10,10,10,13,10,10,10,8,10,10,10,10,10,22,10,10};
        string S("abcdefghivaadsfjklmnoppoiadfqrsqadfrqwetuvwxyz");
        vector<int> output = {5, 87};
        vector<int> res = sln.numberOfLines(widths, S);
        printVector<int>(res);
        CHECK_EQUAL(output == res, true);
    }
}

