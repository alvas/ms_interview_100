/*
 * CustomSortString.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "UnitTest.h"

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        string ans;
        int A[26] = {0};

        for (auto c: T) {
            A[c - 'a']++;
        }

        for (auto c: S) {
            ans += string(A[c - 'a'], c);
            A[c - 'a'] = 0;
        }

        for (int i = 0; i < 26; ++i) {
            if (A[i] != 0) {
                ans += string(A[i], i + 'a');
            }
        }

        return ans;
    }

    string customSortString1(string S, string T) {
        string ans;
        unordered_map<char, int> tMap;
        unordered_set<char> sSet(S.begin(), S.end()), tSet;

        for (auto c: T) {
            tMap[c]++;

            if (sSet.find(c) == sSet.end()) {
                tSet.insert(c);
            }
        }

        for (auto c: S) {
            ans += string(tMap[c], c);
        }

        for (auto c: tSet) {
            ans += string(tMap[c], c);
        }

        return ans;
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
        string S("cba"), T("abcd");
        string ans = sln.customSortString(S, T);
        CHECK_EQUAL("cbad", ans);
    }
}

