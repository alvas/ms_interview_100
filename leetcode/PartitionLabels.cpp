/*
 * PartitionLabels.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "UnitTest.h"

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char, int> eIdx;
        int num = S.size();

        for (int i = 0; i < num; ++i) {
            eIdx[S[i]] = i;
        }

        partition(S, 0, num, eIdx, res);

        return res;
    }

    void partition(string S, int b, int e, unordered_map<char, int> &eIdx, vector<int> &res) {
        if (b == e) {
            return;
        }

        int tmpE = eIdx[S[b]];

        for (int i = b + 1; i <= tmpE; ++i) {
            if (eIdx[S[i]] > tmpE) {
                tmpE = eIdx[S[i]];
            }
        }

        res.push_back(tmpE - b + 1);
        partition(S, tmpE + 1, e, eIdx, res);
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
        string S("ababcbacadefegdehijhklij");
        vector<int> res = sln.partitionLabels(S);
        vector<int> A = {9, 7, 8};
        CHECK_EQUAL(true, A == res);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        string S("a");
        vector<int> res = sln.partitionLabels(S);
        vector<int> A = {1};
        CHECK_EQUAL(true, A == res);
    }

    TEST_FIXTURE(MyFixture, CASE3)
    {
        string S("aa");
        vector<int> res = sln.partitionLabels(S);
        vector<int> A = {2};
        CHECK_EQUAL(true, A == res);
    }

    TEST_FIXTURE(MyFixture, CASE4)
    {
        string S("aab");
        vector<int> res = sln.partitionLabels(S);
        vector<int> A = {2, 1};
        CHECK_EQUAL(true, A == res);
    }

    TEST_FIXTURE(MyFixture, CASE5)
    {
        string S("aba");
        vector<int> res = sln.partitionLabels(S);
        vector<int> A = {3};
        CHECK_EQUAL(true, A == res);
    }

    TEST_FIXTURE(MyFixture, CASE6)
    {
        string S("abc");
        vector<int> res = sln.partitionLabels(S);
        vector<int> A = {1, 1, 1};
        CHECK_EQUAL(true, A == res);
    }
}

