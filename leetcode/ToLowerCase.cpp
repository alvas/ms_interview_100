/*
 * ToLowerCase.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>

#include "UnitTest.h"

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        string res(str.size(), 'a');
        transform(str.begin(), str.end(), res.begin(), [](char a){ return tolower(a); });
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
        string str("ABCDddf;@");
        string res = sln.toLowerCase(str);
        CHECK_EQUAL(res == "abcdddf;@", true);
    }
}

