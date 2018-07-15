/*
 * ShortestDistanceToACharacter.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <string>
#include <vector>

#include "UnitTest.h"

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int numS = S.size();
        vector<int> res(numS, 10001);
        auto itr = S.find(C);
        int dis = 0;

        for (int i = itr; i < numS; ++i) {
            if (S[i] == C) {
                dis = 0;
                res[i] = 0;
            }
            else {
                res[i] = ++dis;
            }
        }

        itr = S.rfind(C);

        for (int i = itr; i >= 0; --i) {
            if (S[i] == C) {
                dis = 0;
            }
            else {
                dis++;

                if (res[i] > dis) {
                    res[i] = dis;
                }
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
        string S("loveleetcode");
        char C = 'e';
        vector<int> output = {3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0};
        vector<int> res = sln.shortestToChar(S, C);
        CHECK_EQUAL(res == output, true);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        string S("aovelaetcode");
        char C = 'a';
        vector<int> output = {0, 1, 2, 2, 1, 0, 1, 2, 3, 4, 5, 6};
        vector<int> res = sln.shortestToChar(S, C);
        CHECK_EQUAL(res == output, true);
    }

    TEST_FIXTURE(MyFixture, CASE3)
    {
        string S("loveadsfleeadsfadsfamsfbchjdtcode");
        char C = 'm';
        vector<int> output = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,1,2,3,4,5,6,7,8,9,10,11,12};
        vector<int> res = sln.shortestToChar(S, C);
        CHECK_EQUAL(res == output, true);
    }
}

