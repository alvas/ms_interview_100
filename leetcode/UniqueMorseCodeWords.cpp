/*
 * UniqueMorseCodeWords.cpp
 * Copyright (C) 2018 qingyun <qingyun.oracle@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */


#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "UnitTest.h"

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> wordMap;

        for (auto w: words) {
            string str;

            for (auto l: w) {
                str += dict[l - 'a'];
            }

            wordMap.insert(str);
        }

        return wordMap.size();
    }

    vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
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
        vector<string> words = {"gin", "zen", "gig", "msg"};
        int ans = sln.uniqueMorseRepresentations(words);
        CHECK_EQUAL(ans, 2);
    }

    TEST_FIXTURE(MyFixture, CASE2)
    {
        vector<string> words = {"book", "daddy", "mirror", "irvine", "goodbye"};
        int ans = sln.uniqueMorseRepresentations(words);
        CHECK_EQUAL(ans, 5);
    }
}

